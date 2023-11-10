#include "test.h"
#include "libft.h"
#include <string.h>

void test_memset()
{
	START_TEST(memset);

	char buffer1[20];
	char buffer2[20];
	TEST_MEMCMP(memset, memset(buffer1, 42, 20), ft_memset(buffer2, 42, 20), 20);
	TEST_MEMCMP(memset, memset(buffer1, 42, (0)), ft_memset(buffer2, 42, 0), 20);

	END_TEST(memset);
}
