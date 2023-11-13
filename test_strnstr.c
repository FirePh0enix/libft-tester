#include "test.h"
#include <bsd/string.h>

void	test_strnstr(void)
{
	char *source = "Hello this is a great test!";

	START_TEST(strnstr);
	TEST_RETURN(strnstr, strnstr(source, "a", 1), "");
	TEST_RETURN(strnstr, strnstr(source, "great", 27), "");
	TEST_RETURN(strnstr, strnstr(source, "", 27), "");
	TEST_RETURN(strnstr, strnstr(source, "!", 27), "");
	TEST_RETURN(strnstr, strnstr(source, "a", 0), "");
	END_TEST(strnstr);
}
