#include "libft.h"
#include "test.h"
#include <stdio.h>
#include <string.h>

void test_strncmp()
{
	START_TEST(strncmp);
	TEST_RETURN_CMP(strncmp, strncmp("Hello world", "Hello world", 11));
	TEST_RETURN_CMP(strncmp, strncmp("Hello world", "Hello", 5));
	TEST_RETURN_CMP(strncmp, strncmp("Hello world", "", 0));
	TEST_RETURN_CMP(strncmp, strncmp("Hello world", "something else", 11));

	// Test if the function is using `unsigned char`
	TEST_RETURN_CMP(strncmp, strncmp("\xff", "\x1", 1));
	END_TEST(strncmp);
}
