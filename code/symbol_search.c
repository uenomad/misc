#define _GNU_SOURCE
#include <link.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <unistd.h>
#include "strtable.h"

#define fdout	 STDOUT_FILENO
#define fderr	 STDERR_FILENO
#define MODE_ALL search_mode == 0
#define MODE_SYM search_mode == 1

typedef uint64_t           bloom_el_t;
typedef Elf64_Sym          Elf_Sym;
typedef unsigned long long ullong;
typedef unsigned char      uchar;

static strtable_t tabsym;
static strtable_t tabdon;
static void *search_deft;
static void *search_next;
static char *search_name;
static int   search_mode;

static int printline()
{
	int i;
	for(i = 0; i < 140; ++i) {
		fprintf(stderr, "-");
	}
	fprintf(stderr, "\n");
}

#define vprint(lines, ...)        \
	{                             \
	if (lines) { printline(); }   \
	fprintf(stderr, __VA_ARGS__); \
	if (lines) { printline(); }   \
	}

static char *string_visibility(uchar visibility)
{
	switch (visibility) {
		case STV_DEFAULT:   return "default";
		case STV_INTERNAL:  return "internal";
		case STV_HIDDEN:    return "hidden";
		case STV_PROTECTED: return "protected";
	}
	return "-";
}

static char *string_bind(uchar binding)
{
	switch (binding) {
		case STB_LOCAL:  return "local";
		case STB_GLOBAL: return "global";
		case STB_WEAK:   return "weak";
		case STB_NUM:    return "NUM DT";
		case STB_LOOS:   return "OS SPEC";
		case STB_HIOS:   return "OS SPEC";
		case STB_LOPROC: return "PROC SPEC";
		case STB_HIPROC: return "PROC SPEC";
	}
	return "-";
}

static char *string_type(uchar type)
{
	switch (type) {
		case STT_NOTYPE:  return "no type";
		case STT_OBJECT:  return "object";
		case STT_FUNC:    return "function";
		case STT_SECTION: return "section";
		case STT_FILE:    return "file";
		case STT_COMMON:  return "common";
		case STT_TLS:     return "tls";
		case STT_NUM:     return "NUM DT";
		case STT_LOOS:    return "OS SPEC";
		case STT_HIOS:    return "OS SPEC";
		case STT_LOPROC:  return "PROC SPEC";
		case STT_HIPROC:  return "PROC SPEC";
	}
	return "-";
}

const Elf_Sym* gnu_lookup(const uint32_t* hashtab)
{
	const uint32_t nbuckets    = hashtab[0];
	const uint32_t symoffset   = hashtab[1];
	const uint32_t bloom_size  = hashtab[2];
	const uint32_t bloom_shift = hashtab[3];
	const bloom_el_t* bloom    = (void *) &hashtab[4];
	const uint32_t* buckets    = (void *) &bloom[bloom_size];
	const uint32_t* chain      = &buckets[nbuckets];
	return NULL;
}

static uint count_from_hash(Elf64_Addr h_addr)
{
	typedef struct gnu_ht_s {
		uint bucket_count;
		uint sym_offset;
		uint bloom_size;
		uint bloom_shift;
	} gnu_ht_t;

	uint *addr_bucket;
	void *addr_chain;
	void *addr_aux;
	uint last_sym;
	gnu_ht_t* h;
	int i;

	h           = (gnu_ht_t *) h_addr;
	addr_aux    = (void *) h_addr + sizeof(gnu_ht_t) + (sizeof(ullong) * h->bloom_size);
	addr_bucket = (uint *) addr_aux;
	addr_chain  = addr_aux + (sizeof(uint) * h->bucket_count);
	last_sym    = 0;
	// Locate the chain that handles the largest index bucket.
	for (i = 0; i < h->bucket_count; ++i) {
		uint bucket = *addr_bucket;
		if (last_sym < bucket) {
			last_sym = bucket;
		}
		addr_bucket++;
	}
	if (last_sym < h->sym_offset) {
		return h->sym_offset;
	}
	// Walk the bucket's chain to add the chain length to the total.
	for (;;) {
		uint *chain_entry = (uint *) (addr_chain + (last_sym - h->sym_offset) * sizeof(uint));
		// If the low bit is set, this entry is the end of the chain.
		if (*chain_entry & 1) {
			break;
		}
		last_sym++;
	}
	return last_sym;
}

// Callback receiving three arguments: info, which is a pointer to a structure
// containing information about the shared object; size, that is the size of
// the structure pointed to by info; and data, which is a copy of whatever value
// was passed by the calling program as the second argument (also named data) in
// the call to dl_iterate_phdr().
static int callback(struct dl_phdr_info *info, size_t size, void *data)
{
	Elf64_Dyn  *segment;
	Elf64_Sym  *symbols;
	Elf64_Word *hash;
	Elf64_Phdr *phdr;
	Elf64_Word  n;
	Elf64_Word  j;
	char       *strtab;
	int         virtual_obj;
	int         i;
	Elf64_Addr  addr_offs;
	Elf64_Addr  addr_full;
	uchar       st_type;
	uchar       st_bind;
	uchar       st_visibility;
	Elf64_Addr  addr_deft;
	Elf64_Addr  addr_next;
	char       *str_deft;
	char       *str_next;
	int         name_len;
	char       *str_name;
	char       *str_prefix;

	// struct dl_phdr_info {
	//     ElfW(Addr)        dlpi_addr;  /* Base address of object */
	//     const char       *dlpi_name;  /* (Null-terminated) name of object */
	//     const ElfW(Phdr) *dlpi_phdr;  /* Pointer to array of ELF program
	//                                      headers for this object */
	//     ElfW(Half)       dlpi_phnum;  /* # of items in dlpi_phdr */
	//     ullong            dlpi_adds;  /* Incremented when a new object may
	//                                      have been added */
	//     ullong            dlpi_subs;  /* Incremented when an object may
	//                                      have been removed */
	//     size_t       dlpi_tls_modid;  /* If there is a PT_TLS segment, its
	//                                      module ID as used in TLS
	//                                      relocations, else zero */
	//     void         *dlpi_tls_data;  /* The address of the calling thread's
	//                                      instance of this module's PT_TLS
	//                                      segment, if it has one and it has
	//                                      been allocated in the calling
	//                                      thread, otherwise a null pointer */
	// };
	if (MODE_ALL) {
		vprint(1, "%s'%s'%s (%d segments)\n",
			   COL_RED, info->dlpi_name, COL_CLR, info->dlpi_phnum);
	}
	// If it has no name, it is a virtual shared object.
	virtual_obj = (strlen(info->dlpi_name) == 0);
	// Now iterating over all binaries program headers
	for (i = 0, n = 0; i < info->dlpi_phnum; i++)
	{
		// dlpi_phdr is apointer to array of ELF program headers for this
		// object. The dlpi_phnum field indicates the size of this array.
		phdr = (Elf64_Phdr *) &info->dlpi_phdr[i];

		if (MODE_ALL) {
			vprint(0, "- %2d, type %10u, header: vr. addr %16p, ph. addr %18p, file size: %8lu, mem. size: %8lu\n",
				   i, phdr->p_type, (void *) (info->dlpi_addr + phdr->p_vaddr),
				   (void *) phdr->p_paddr, phdr->p_filesz, phdr->p_memsz);
		}
		// If not dynamic linker data
		if(phdr->p_type != PT_DYNAMIC) {
			continue;
		}

		// If an object file participates in dynamic linking, its program header
		// table will have an element of type PT_DYNAMIC. This segment contains
		// the .dynamic section.
		//
		// typedef struct {
		//     Elf64_Sxword d_tag;  /* Dynamic entry type */
		//     union {
		//      Elf64_Xword d_val;  /* Integer value */
		//      Elf64_Addr  d_ptr;  /* Address value */
		//    } d_un;
		// } Elf64_Dyn;
		//
		// Calculation of the location of a particular program header, in
		// virtual memory.
		segment = (Elf64_Dyn *) (info->dlpi_addr + phdr->p_vaddr);
		//vprint(0, "%llu %llu %p\n", segment->d_tag, segment->d_un.d_val, segment->d_un.d_ptr);
		// PT_DYNAMIC segments are composed of tags
		while (segment->d_tag != DT_NULL)
		{
			// Symbol hash table
			// /https://flapenguin.me/elf-dt-hash)
			if (segment->d_tag == DT_HASH) {
				hash = (Elf64_Word *) segment->d_un.d_ptr;
				if (!virtual_obj) n = hash[1];
			}
			// Newer version of DT_HASH symbol hash table
			// (https://flapenguin.me/elf-dt-gnu-hash)
			else if (segment->d_tag == DT_GNU_HASH) {
				// If 'linux-vdso.so.1' or '' and ptr 352 = CRASH
				// In the future, use the name to detect it is the vdso instead
				// the hardcode of '352'.
				int vdso = (strcmp(info->dlpi_name, "linux-vdso.so.1") == 0) ||
						   (strlen(info->dlpi_name) == 0);

				if (n == 0 && ((ullong) segment->d_un.d_ptr) != 352) {
				//if (n == 0) {
					n = count_from_hash((ullong) segment->d_un.d_ptr);
				}
			}
			else if (segment->d_tag == DT_STRTAB) {
				strtab = (char *) segment->d_un.d_ptr;
			}
			else if (segment->d_tag == DT_SYMTAB) {
				//
				if (MODE_ALL && n > 0) {
					printline();
					tprintf(&tabdon, "symbol name||address||type||#  ||bind||#  ||vis||#  ");
					tprintf(&tabdon, "-----------||-------||----||---||----||---||---||---");
				}

				symbols = (ElfW(Sym*)) segment->d_un.d_ptr;

				for (j = 1; j < n; j++)
				{
					//
					addr_offs = symbols[j].st_value;
					addr_full = info->dlpi_addr + addr_offs;
					str_name  = &strtab[symbols[j].st_name];
					// Symbol Types
					st_type = ELF64_ST_TYPE(symbols[j].st_info);
					st_bind = ELF64_ST_BIND(symbols[j].st_info);
					st_visibility = ELF64_ST_VISIBILITY(symbols[j].st_other);

					//
					if (MODE_ALL) {
						tprintf(&tabdon, "%s||%p||%s||(%d)||%s||(%d)||%s||(%d)",
								str_name, (void *) addr_offs,
								string_type(st_type), st_type,
								string_bind(st_bind), st_bind,
								string_visibility(st_visibility), st_visibility);
					}
					//
					if (MODE_SYM && strcmp(search_name, str_name) == 0)
					{
						addr_deft = (Elf64_Addr) (search_deft - info->dlpi_addr);
						addr_next = (Elf64_Addr) (search_next - info->dlpi_addr);
						str_deft = "default";
						str_next = "next";

						if (addr_deft != addr_offs) {
							str_deft = "-";
						}
						if (addr_next != addr_offs) {
							str_next = "-";
						}
						//
						name_len = strlen(info->dlpi_name);
						str_name = (char *) info->dlpi_name;
						str_prefix = "";
						// If name is greater than the 60 chars of the column...
						if (name_len > 60) {
							str_name += (name_len-60);
							str_prefix = "...";
						}
						tprintf(&tabsym, "%s%s||%p||%p||%s||(%d)||%s||(%d)||%s||(%d)||%s||%s",
								str_prefix, str_name,
								(void *) addr_full, (void *) addr_offs,
								string_type(st_type), st_type,
								string_bind(st_bind), st_bind,
								string_visibility(st_visibility), st_visibility,
								str_deft, str_next);
					}
				}

				if (MODE_ALL && n > 0) {
					printline();
				}
			}
			++segment;
		}
	}

	return 0;
}

void search(int argc, char **argv, char **environ)
{
	// Search mode
	search_mode = 0;
	// Print tables initializations
	tprintf_init(&tabdon, fdout, STR_MODE_DEF, "40 18 10 5 8 5 10 5");
	tprintf_init(&tabsym, fdout, STR_MODE_DEF, "70 16 10 10 4 8 4 8 4 8 5");

	if ((search_name = getenv("SEARCH_SYM")) != NULL) {
		vprint(1, "looking for symbols '%s'\n", search_name);
		search_deft = dlsym(RTLD_DEFAULT, search_name);
		search_next = dlsym(RTLD_NEXT, search_name);
		search_mode = 1;
	}
	// The dl_iterate_phdr() function walks through the list of an application's
	// shared objects and calls the function callback once for each object,
	// until either all shared objects have been processed or callback returns a
	// nonzero value.
	dl_iterate_phdr(callback, NULL);

	printline();
}

#ifdef MAIN
// Binary
int main(int argc, char *argv[])
{
	search(argc, argv, NULL);
	return 0;
}
#else
// Injection (you can use attribute constructor too)
__attribute__((section(".init_array"))) typeof(search) *__init = search;
#endif