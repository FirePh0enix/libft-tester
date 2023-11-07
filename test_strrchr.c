#include "test.h"
#include <string.h>

void test_strrchr()
{
	START_TEST(strrchr);
	TEST_RETURN_STRCMP(strrchr, strrchr("Hello world!", 'w'));
	TEST_RETURN_STRCMP(strrchr, strrchr("Hello world!", 'o'));
	TEST_RETURN_STRCMP(strrchr, strrchr("Hello world!", 'z'));
	TEST_RETURN_STRCMP(strrchr, strrchr("", 'w'));
	END_TEST(strrchr);
}
