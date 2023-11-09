#include <stdio.h>
#include <stdlib.h>

extern void *__libc_malloc(size_t n);
extern void __libc_free(void *p);

size_t malloc_count = 0;
size_t free_count = 0;
static int enable = 1;

// malloc & free are weak symbols so they can be overwritten

void *malloc(size_t n)
{
	if (!enable)
		return (0);
	void *ptr = __libc_malloc(n);
	malloc_count += 1;
	return (ptr);
}

void free(void *p)
{
	if (!p)
		printf("Free called on NULL!");
	__libc_free(p);
	free_count += 1;
}

void reset_memory_stats()
{
	malloc_count = 0;
	free_count = 0;
}

void enable_malloc()
{
	enable = 1;
}

void disable_malloc()
{
	enable = 0;
}
