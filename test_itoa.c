#include "libft.h"
#include "test.h"
#include <string.h>

void test_itoa()
{
	START_TEST(itoa);
	TEST_RETURN_STRCMP_SINGLE(itoa, ft_itoa(-42), "-42");
	TEST_RETURN_STRCMP_SINGLE(itoa, ft_itoa(-2147483648), "-2147483648");
	TEST_RETURN_STRCMP_SINGLE(itoa, ft_itoa(2147483647), "2147483647");
	TEST_RETURN_STRCMP_SINGLE(itoa, ft_itoa(0), "0");
	END_TEST(itoa);
}
