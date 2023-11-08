#include "test.h"
#include <ctype.h>

void test_isalpha()
{
	START_TEST(isalpha);
	TEST_RETURN_BOOL(isalpha, isalpha('A'));
	TEST_RETURN_BOOL(isalpha, isalpha('Z'));
	TEST_RETURN_BOOL(isalpha, isalpha('a'));
	TEST_RETURN_BOOL(isalpha, isalpha('z'));
	TEST_RETURN_BOOL(isalpha, isalpha('0'));
	TEST_RETURN_BOOL(isalpha, isalpha(1234));
	END_TEST(isalpha);
}
