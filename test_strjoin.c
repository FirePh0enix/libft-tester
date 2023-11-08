#include "test.h"
#include "libft.h"
#include <string.h>

void test_strjoin()
{
	START_TEST(strjoin);
	TEST_RETURN_STRCMP_SINGLE(strjoin, ft_strjoin("Hello ", "world~"), "Hello world~");
	END_TEST(strjoin);
}
