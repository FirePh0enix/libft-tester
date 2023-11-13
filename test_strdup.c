#include "test.h"
#include <string.h>

void test_strdup()
{
	START_TEST(strdup);
	TEST_RETURN_STRCMP(strdup, strdup("Hello world!"));

	TEST_RETURN_STRCMP(strdup, strdup(""));

	TEST_RETURN_STRCMP(strdup, strdup("   GP B3ST CHM4P"));

	TEST_RETURN_STRCMP(strdup, strdup("\0"));

	disable_malloc();

	TEST_RETURN_EQ(strdup, strdup(""), NULL);

	TEST_RETURN_EQ(strdup, strdup("Hello world!"), NULL);

	TEST_RETURN_EQ(strdup, strdup("GP B3ST CHM4P"), NULL);

	TEST_RETURN_EQ(strdup, strdup("\0"), NULL);

	enable_malloc();

	END_TEST(strdup);
}
