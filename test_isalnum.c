#include "test.h"
#include <ctype.h>
#include "libft.h"

void test_isalnum()
{
	START_TEST(isalnum);
	TEST_RETURN_BOOL(isalnum, isalpha('A'));
	TEST_RETURN_BOOL(isalnum, isalpha('Z'));
	TEST_RETURN_BOOL(isalnum, isalpha('a'));
	TEST_RETURN_BOOL(isalnum, isalpha('z'));
	TEST_RETURN_BOOL(isalnum, isalpha('0'));
	TEST_RETURN_BOOL(isalnum, isalpha('9'));
	TEST_RETURN_BOOL(isalnum, isalpha(4321));
	TEST_RETURN_BOOL(isalnum, isalpha(-1232));
	END_TEST(isalnum);
}
