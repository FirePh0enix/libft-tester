#include "test.h"
#include "libft.h"
#include <string.h>

void test_bzero()
{
	START_TEST(bzero);

	char buffer1[20];
	char buffer2[20];
	bzero(buffer1, 20);
	ft_bzero(buffer2, 20);
	TEST_MEMCMP(bzero, buffer1, buffer2, 20);

	END_TEST(bzero);
}
