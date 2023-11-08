#include "libft.h"
#include "test.h"
#include <string.h>

void test_split()
{
	START_TEST(split);

	char *table[] = { "This", "is", "a", "test" };
	TEST_RETURN_STRCMP_ARRAY(split, ft_split("This is a test", ' '), table, 4);

	END_TEST(split);
}
