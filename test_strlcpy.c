#include "test.h"
#include "libft.h"
#include <bsd/string.h>

#define TEST_STRLCPY(NAME, SIZE, INIT, SRC, TO_COPY_SIZE) \
	do { \
		char dst1[SIZE] = INIT; \
		char dst2[SIZE] = INIT; \
		size_t res_std = strlcpy(dst1, SRC, TO_COPY_SIZE); \
		size_t res_ft = ft_strlcpy(dst2, SRC, TO_COPY_SIZE); \
		if (memcmp(dst1, dst2, SIZE) == 0 && res_std == res_ft) { \
			printf("%s", SUCCESS); \
			_OK_TEST(NAME) += 1; \
		} else { \
			printf("%s (`%s` / `%zu` !=  `%s` / `%zu`)", FAIL, dst1, res_std, dst2, res_ft); \
			_FAIL_TEST(NAME) += 1; \
		} \
	} while (0)

void test_strlcpy()
{
	START_TEST(strlcpy);
	TEST_STRLCPY(strlcpy, 26, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "0123456789", 10);
	END_TEST(strlcpy);
}
