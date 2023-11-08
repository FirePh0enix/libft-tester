#include "test.h"
#include "libft.h"
#include <bsd/string.h>

#define TEST_STRLCAT(NAME, SIZE, INIT, SRC, TO_COPY_SIZE) \
	do { \
		printf("Test %d ", TEST_INDEX(NAME)); \
		char dst1[SIZE] = INIT; \
		char dst2[SIZE] = INIT; \
		size_t res_std = strlcat(dst1, SRC, TO_COPY_SIZE); \
		size_t res_ft = ft_strlcat(dst2, SRC, TO_COPY_SIZE); \
		if (memcmp(dst1, dst2, SIZE) == 0 && res_std == res_ft) { \
			printf("%s", SUCCESS); \
			_OK_TEST(NAME) += 1; \
		} else { \
			printf("%s (`%s` / %zu (std) !=  `%s` / %zu (ft))", FAIL, dst1, res_std, dst2, res_ft); \
			_FAIL_TEST(NAME) += 1; \
		} \
		printf("\n"); \
	} while (0)

void test_strlcat()
{
	START_TEST(strlcat);
	TEST_STRLCAT(strlcat, 20, "Hello ", "world!", 12);
	TEST_STRLCAT(strlcat, 20, "Hello ", "world!", 0);
	TEST_STRLCAT(strlcat, 20, "Hello ", "world!", 4);
	TEST_STRLCAT(strlcat, 20, "Hello ", "world!", 42);
	END_TEST(strlcat);
}
