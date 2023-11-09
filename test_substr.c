#include "libft.h"
#include "test.h"
#include <string.h>

void test_substr()
{
	START_TEST(substr);
	TEST_RETURN_STRCMP_SINGLE(substr, ft_substr("Hello world!", 6, 5), "world");
	TEST_RETURN_STRCMP_SINGLE(substr, ft_substr("Hello world!", 6, 30), "world!");

	disable_malloc();
	TEST_RETURN_EQ(substr, ft_substr("Hello world!", 6, 5), NULL);
	enable_malloc();

	END_TEST(substr);
}
