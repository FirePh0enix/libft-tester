#include <stddlib.h>

extern void *__libc_malloc(size_t n);
extern void __libc_free(void *p);

size_t malloc_count = 0;
size_t free_count = 0;

// malloc & free are weak symbols so they can be overwritten

void *malloc(size_t n)
{
    void *ptr = __libc_malloc();
    malloc_count += 1;
    return (ptr);
}

void free(void *p)
{
    __libc_free(p);
    free_count += 1;
}

void reset_memory_stats()
{
    malloc_count = 0;
    free_count = 0;
}
