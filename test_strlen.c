#include "test.h"
#include "libft.h"
#include <string.h>

void test_strlen()
{
	START_TEST(strlen);
	TEST_RETURN(strlen, strlen("Hello world!"), "");
	TEST_RETURN(strlen, strlen(""), "");
	END_TEST(strlen);
}
