#include "test.h"
#include "libft.h"
#include <ctype.h>

void test_isascii()
{
	START_TEST(isascii);
	TEST_RETURN_BOOL(isascii, isascii(-128));
	TEST_RETURN_BOOL(isascii, isascii(127));
	TEST_RETURN_BOOL(isascii, isascii(-432));
	TEST_RETURN_BOOL(isascii, isascii(-1242));
	END_TEST(isascii);
}
