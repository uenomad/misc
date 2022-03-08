#ifndef MISC_SYMBOL_SEARCH_H
#define MISC_SYMBOL_SEARCH_H

// ELF is a format for storing programs or fragments of programs on disk,
// created as a result of compiling and linking, and shared objects. An ELF
// is divided into headers, segments and sections. The loadable segments
// contribute to the program's process image and, thus, provide an execution
// view of the object file. Sections are inside segments and, on the other
// hand, hold the bulk of object file information for the linking view:
// instructions, data, symbol tables, relocation information, etc.
//
// Headers
// -------
// .elf_header: loaded at the very beginning of the elf file. Contains
//  information about how the rest of the file is laid out.
// .program_headers: These specify where in the file the program segments
//  are located, and where they need to be loaded into memory. Each program
//  header has an associated type. Only headers with a type of PT_LOAD
//  describe a loadable segment.
//
// Segments
// --------
// .PT_PHDR: program header segment.
// .PT_LOAD: a segment loaded in memory, i.e. the text segment for program
//  code, or data segment for global variables and dynamic linking
//  information.
// .PT_DYNAMIC: dynamic linker data. Contains a list of tags and pointers,
//  including libraries, symbols, location of Global Offset Table (GOT),
//  relocation information, etc.
// .PT_INTERP, generally the location of the dynamic linker
//  /lib/linux-ld.so.2.
// .PT_NOTE: auxiliary information.
// .PT_TLS: thread local storage.
//
// Program header are structures of the following form:
//      typedef struct {
//          Elf64_Word  p_type;    /* Segment type  */
//          Elf64_Off   p_offset;  /* Segment file offset */
//          Elf64_Addr  p_vaddr;   /* Segment virtual address */
//          Elf64_Addr  p_paddr;   /* Segment physical address */
//          Elf64_Word  p_filesz;  /* Segment size in file */
//          Elf64_Word  p_memsz;   /* Segment size in memory */
//          Elf64_Word  p_flags;   /* Segment flags */
//          Elf64_Word  p_align;   /* Segment alignment */
//      } Elf64_Phdr;
//
// p_type: PT_PHDR, PT_LOAD, PT_DYNAMIC, etc.
// p_offset: where in the file is this data.
// p_vaddr: where you should start to put this segment in virtual memory.
// p_flags: readable, writable, executable, etc.
//
// Sections
// --------
// .text: pogram code
// .rodata: read only data.
// .plt: procedure linkable table (PLT). Contains code necessary for the
//  dynamic linker to call functions from shared libraries.
// .data: initialized global variables.
// .bss: uninitialized global variables.
// .got.plt: Global Offset Table. Works with .plt.
// .dynsym: Symbol information imported from shared libraries.
// .dynstr: Name of each symbol.
// .symtab: More symbol information of type Elf64_Sym.
// .strtab: Symbol string table that is referenced by st_name from
//  Elf64_Sym of .symtab.
// .shstrtab: String table containing the name of each section.
// .rel.*: Information about relocation.
// .hash: A hash table for symbol lookup.
// .ctors and .dtors: Function pointers to constructors and destructors.
//
// How the headers are stored:
// Neither the section nor the program headers have fixed positions, they
// can be located anywhere in an ELF file. To find them the ELF header is
// used, which is located at the very start of the file. The first bytes
// contain the elf magic "\x7fELF", followed by the class ID (32 or 64 bit
// ELF file), the data format ID (little endian/big endian), the machine
// type, etc. At the end of the ELF header are then pointers to the section
// and program headers.
//
// The kernel loads the parts specified in the LOAD directives in the
// program header into memory. If an INTERP entry is present,
// the interpreter is loaded too. Statically linked binaries can do without
// an interpreter; dynamically linked programs always need /lib/ld-linux.so
// as interpreter because it includes some startup code, loads shared
// libraries needed by the binary, and performs relocations.
//
//
// Symbol loading:
//	https://greek0.net/elf.html

// https://man7.org/linux/man-pages/man3/dl_iterate_phdr.3.html
// https://docs.google.com/presentation/d/1O_-iMT-O8Vv2lRbg4oXdyUpCs2SwqQaFW8Y6DylVyyM/edit#slide=id.g7181106b14_0_67
// https://wiki.osdev.org/ELF
// https://flapenguin.me/elf-dt-hash
// https://docs.oracle.com/cd/E19683-01/816-1386/chapter6-79797/index.html
// https://web.archive.org/web/20171129031316/http://nairobi-embedded.org/040_elf_sec_seg_vma_mappings.html
// https://web.archive.org/web/20150602071342/http://nairobi-embedded.org/img/elf/elf_link_vs_exec_view.jpg
// https://wiki.osdev.org/Symbol_Table
// https://docs.oracle.com/cd/E19683-01/816-1386/chapter6-42444/index.html

void search(int argc, char **argv, char **environ);

#endif //MISC_SYMBOL_SEARCH_H
