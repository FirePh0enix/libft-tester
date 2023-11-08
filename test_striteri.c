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

	END_TEST(striteri);
}
