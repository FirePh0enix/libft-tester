#include "libft.h"
#include "test.h"
#include <string.h>

void test_memmove()
{
	START_TEST(memmove);

	char buffer1[13] = "Hello world!";
	char buffer2[13] = "Hello world!";
	TEST_MEMCMP(memmove, memmove(buffer1, buffer1 + 4, 9), ft_memmove(buffer2, buffer2 + 4, 9), 13);

	char buffer3[] = "GANGPLANK BEST CHAMP";
	char buffer4[] = "GANGPLANK BEST CHAMP";
	TEST_MEMCMP(memmove, memmove(buffer3, buffer3, 0), ft_memmove(buffer4, buffer4, 0), strlen(buffer3));
	END_TEST(memmove);
}
