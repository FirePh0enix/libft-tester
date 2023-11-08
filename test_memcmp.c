#include "test.h"
#include "libft.h"
#include <string.h>

void test_memcmp()
{
	START_TEST(memcmp);
	TEST_RETURN_CMP(memcmp, memcmp("Hello", "Hello", 5));
	TEST_RETURN_CMP(memcmp, memcmp("Hello world", "Hello", 5));
	TEST_RETURN_CMP(memcmp, memcmp("Hello world", "something else", 11));
	END_TEST(memcmp);
}
