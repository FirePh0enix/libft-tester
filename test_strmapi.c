#include "libft.h"
#include "test.h"
#include <ctype.h>
#include <string.h>

static char to_upper(unsigned int i, char c)
{
	(void) i;
	return toupper(c);
}

void test_strmapi()
{
	START_TEST(strmapi);
	TEST_RETURN_STRCMP_SINGLE(strmapi, ft_strmapi("hello world", to_upper), "HELLO WORLD");

	disable_malloc();
	TEST_RETURN_EQ(strmapi, ft_strmapi("hello world", to_upper), NULL);
	enable_malloc();

	END_TEST(strmapi);
}
