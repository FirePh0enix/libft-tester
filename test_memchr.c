#include "libft.h"
#include "test.h"
#include <string.h>

void test_memchr()
{
	START_TEST(memchr);
	TEST_RETURN_STRCMP(memchr, memchr("Hello world!", 'w', 13));
	TEST_RETURN_STRCMP(memchr, memchr("Hello world!", 'z', 13));
	TEST_RETURN_STRCMP(memchr, memchr("Hello world!", '\0', 13));
	TEST_RETURN_STRCMP(memchr, memchr("", 'w', 0));
	END_TEST(memchr);
}
