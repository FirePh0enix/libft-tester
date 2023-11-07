#include "test.h"
#include <string.h>

void test_strchr()
{
	START_TEST(strchr);
	TEST_RETURN_STRCMP(strchr, strchr("Hello world!", 'w'));
	TEST_RETURN_STRCMP(strchr, strchr("Hello world!", 'z'));
	TEST_RETURN_STRCMP(strchr, strchr("Hello world!", '\0'));
	TEST_RETURN_STRCMP(strchr, strchr("", 'w'));
	END_TEST(strchr);
}
