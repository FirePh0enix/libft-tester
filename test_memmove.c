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
	TEST_MEMCMP(memmove, memmove(buffer3, buffer3, 242), ft_memmove(buffer4, buffer4, 242), strlen(buffer3));
	TEST_MEMCMP(memmove, memmove(buffer3, buffer3, 9), ft_memmove(buffer4, buffer4, 9), strlen(buffer3));
	
	char buffer5[] = "";
	char buffer6[] = "";
	TEST_MEMCMP(memmove, memmove(buffer5, buffer5, 9), ft_memmove(buffer6, buffer6, 6), strlen(buffer5));

	char buffer7[] = "\0";
	char buffer8[] = "\0";
	TEST_MEMCMP(memmove, memmove(buffer7, buffer7, 9), ft_memmove(buffer8, buffer8, 6), strlen(buffer7));
	END_TEST(memmove);
}
