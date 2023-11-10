#include "test.h"
#include <string.h>

void test_strdup()
{
	START_TEST(strdup);
	TEST_RETURN_STRCMP(strdup, strdup("Hello world!"));

	disable_malloc();
	TEST_RETURN_EQ(strdup, strdup("Hello world!"), NULL);
	enable_malloc();

	END_TEST(strdup);
}
