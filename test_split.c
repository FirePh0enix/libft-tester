#include "libft.h"
#include "test.h"
#include <string.h>

void test_split()
{
	START_TEST(split);

	char *table[] = { "This", "is", "a", "test" };
	TEST_RETURN_STRCMP_ARRAY(split, ft_split("This is a test", ' '), table, 4);

	char *table2[] = { "This is a test" };
	TEST_RETURN_STRCMP_ARRAY(split, ft_split("This is a test", '\n'), table2, 1);

	END_TEST(split);
}
