#include "libft.h"
#include "test.h"
#include <ctype.h>

void test_tolower()
{
	START_TEST(tolower);
	TEST_RETURN(tolower, tolower('a'), "");
	TEST_RETURN(tolower, tolower('A'), "");
	TEST_RETURN(tolower, tolower('~'), "");
	TEST_RETURN(tolower, tolower(4523), "Non-ascii characters are not handled properly");
	END_TEST(tolower);
}
