#include "libft.h"
#include "test.h"
#include <string.h>

void test_memmove()
{
	START_TEST(memmove);

	char buffer1[13] = "Hello world!";
	char buffer2[13] = "Hello world!";
	TEST_MEMCMP(memmove, memcpy(buffer1, buffer1 + 4, 9), ft_memcpy(buffer2, buffer2 + 4, 9), 13);

	END_TEST(memmove);
}
