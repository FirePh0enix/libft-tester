#include "test.h"
#include "libft.h"
#include <string.h>

void test_memcmp()
{
	START_TEST(memcmp);
	TEST_RETURN_CMP(memcmp, memcmp("Hello", "Hello", 5));
	TEST_RETURN_CMP(memcmp, memcmp("Hello", "Hello", 0));
	TEST_RETURN_CMP(memcmp, memcmp("Hello", "Hello", 2));
	TEST_RETURN_CMP(memcmp, memcmp("Hello", "", 242));
	TEST_RETURN_CMP(memcmp, memcmp("\0", "Hello", 242));
	TEST_RETURN_CMP(memcmp, memcmp("Hello world", "Hello", 5));
	TEST_RETURN_CMP(memcmp, memcmp("Hello world", "something else", 11));

	// Test if the function is using `unsigned char`
	TEST_RETURN_CMP(memcmp, memcmp("\xff", "\0", 2));
	END_TEST(memcmp);
}
