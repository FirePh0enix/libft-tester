#include "libft.h"
#include "test.h"
#include <string.h>

void test_memcpy()
{
	START_TEST(memcpy);

	char buffer1[13];
	char buffer2[13];
	TEST_MEMCMP(memcpy, memcpy(buffer1, "Hello world!", 13), ft_memcpy(buffer2, "Hello world!", 13), 13);

	END_TEST(memcpy);
}
