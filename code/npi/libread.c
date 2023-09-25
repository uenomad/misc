#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ssize_t (*next_write) (int fildes, const void *buf, size_t nbyte);
ssize_t (*next_read)  (int fildes, void *buf, size_t nbyte);

static int debug_enabled;

#define debug(...) \
    if (debug_enabled) { \
        fprintf(stderr, __VA_ARGS__); \
        fprintf(stderr, "\n"); \
    }

ssize_t write(int fildes, const void *buf, size_t nbyte)
{
    debug("write  %03d | %16p | %lu", fildes, buf, nbyte);
    return next_write(fildes, buf, nbyte);
}

ssize_t read(int fildes, void *buf, size_t nbyte)
{
    debug("read   %03d | %16p | %lu", fildes, buf, nbyte);
    return next_read(fildes, buf, nbyte);
}

void  __attribute__ ((constructor)) next_symbols_loader()
{
    debug_enabled = (getenv("DEBUG") != NULL);
    next_write = dlsym(RTLD_NEXT, "write");
    next_read  = dlsym(RTLD_NEXT, "read");
}
