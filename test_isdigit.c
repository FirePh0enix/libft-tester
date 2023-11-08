#include "libft.h"
#include "test.h"
#include <ctype.h>

void test_isdigit()
{
	START_TEST(isdigit);
	TEST_RETURN_BOOL(isdigit, isdigit('a'));
	TEST_RETURN_BOOL(isdigit, isdigit('0'));
	TEST_RETURN_BOOL(isdigit, isdigit('9'));
	TEST_RETURN_BOOL(isdigit, isdigit('~'));
	TEST_RETURN_BOOL(isdigit, isdigit(1234));
	TEST_RETURN_BOOL(isdigit, isalpha(-1232));
	END_TEST(isdigit);
}
