#include "libft.h"
#include "test.h"
#include <ctype.h>
#include <string.h>

static void to_upper(unsigned int i, char *c)
{
	(void) i;
	*c = toupper(*c);
}

void test_striteri()
{
	START_TEST(striteri);

	char s[] = "hello world";
	ft_striteri(s, to_upper);
	TEST_RETURN_STRCMP_SINGLE(striteri, s, "HELLO WORLD");

	char test1[] = "hello world";
	ft_striteri(NULL, to_upper);
	TEST_RETURN_STRCMP_SINGLE(striteri, test1, "hello world");

	END_TEST(striteri);
}
