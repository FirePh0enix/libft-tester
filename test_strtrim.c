#include "libft.h"
#include "test.h"
#include <string.h>

void test_strtrim()
{
	START_TEST(strtrim);
	TEST_RETURN_STRCMP_SINGLE(strtrim, ft_strtrim("   \nHello world!\n  ", " \n"), "Hello world!");
	END_TEST(strtrim);
}
