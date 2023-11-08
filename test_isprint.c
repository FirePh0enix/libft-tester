#include "test.h"
#include <ctype.h>

void test_isprint()
{
	START_TEST(isprint);
	TEST_RETURN_BOOL(isprint, isprint('A'));
	TEST_RETURN_BOOL(isprint, isprint(12));
	TEST_RETURN_BOOL(isprint, isprint(127));
	END_TEST(isprint);
}
