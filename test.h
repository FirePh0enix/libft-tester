#ifndef TEST_H
# define TEST_H

#include <assert.h>
#include <stdio.h>
#include "libft.h"

//#define STRINGIFY(s) _STRINGIFY(s)
//#define _STRINGIFY(s) #s

#define RED_S "\033[1;31m"
#define GREEN_S "\033[1;32m"
#define RESET "\033[0m"

#define SUCCESS GREEN_S "SUCCESS" RESET
#define FAIL RED_S "FAIL" RESET

#define RED(s) RED_S s RESET
#define GREEN(s) GREEN_S s RESET

#define _OK_TEST(NAME) test_ ## NAME ## _OK
#define _FAIL_TEST(NAME) test_ ## NAME ## _FAIL

#define _GLOBAL_OK_TEST test_GLOBAL
#define _GLOBAL_FAIL_TEST test_GLOBAL

/*
	Memory leak detection
*/

extern size_t malloc_count;
extern size_t free_count;

void reset_memory_stats();

#define CHECK_MEMORY_LEAK(NAME) \
	do { \
		if (malloc_count > free_count) { \
			printf("💣 Memory leaks detected : %d malloc, %d free 💣\n", malloc_count, free_count); \
		} else if (malloc_count < free_count) { \
			printf("💣 Too many free : %d malloc, %d free 💣\n", malloc_count, free_count); \
		} \
		reset_memory_stats(); \
	} while (0)

/*
	Start/End macro
*/

#define START_TEST(NAME) \
	printf("Testing '%s'\n", #NAME); \
	static int _OK_TEST(NAME) = 0; \
	static int _FAIL_TEST(NAME) = 0; \

#define END_TEST(NAME) \
	do { \
		printf("Testing ended "); \
		if (_FAIL_TEST(NAME) == 0) { \
			printf("%sall %d%s tests succeeded 🎉\n\n", GREEN_S, _OK_TEST(NAME), RESET); \
		} else { \
			printf("%s%d%s succeeded, %s%d%s failed 💣\n\n", GREEN_S, _OK_TEST(NAME), RESET, RED_S, _FAIL_TEST(NAME), RESET); \
		} \
	} while (0)

#define TEST_INDEX(NAME) _OK_TEST(NAME) + _FAIL_TEST(NAME)

/*
	The actual tests macro
*/

/*
	Test the return value of the function
*/
#define TEST_RETURN(NAME, FN) \
	do { \
		unsigned long res_std = (unsigned long) FN; \
		unsigned long res_ft = (unsigned long) ft_ ## FN; \
		printf("Test %d ", TEST_INDEX(NAME)); \
		if (res_std == res_ft) { \
			printf("%s", SUCCESS); \
			_OK_TEST(NAME) += 1; \
		} else { \
			printf("%s (`%zu` (std) != `%zu` (ft))", FAIL, res_std, res_ft); \
			_FAIL_TEST(NAME) += 1; \
		} \
		printf(" `%s`\n", #FN); \
	} while (0)

#define TEST_RETURN_INT(NAME, FN) \
	do { \
		int res_std = (int) FN; \
		int res_ft = (int) ft_ ## FN; \
		printf("Test %d ", TEST_INDEX(NAME)); \
		if (res_std == res_ft) { \
			printf("%s", SUCCESS); \
			_OK_TEST(NAME) += 1; \
		} else { \
			printf("%s (`%d` (std) != `%d` (ft))", FAIL, res_std, res_ft); \
			_FAIL_TEST(NAME) += 1; \
		} \
		printf(" `%s`\n", #FN); \
	} while (0)

#define TEST_RETURN_CMP(NAME, FN) \
	do { \
		int res_std = (int) FN; \
		int res_ft = (int) ft_ ## FN; \
		printf("Test %d ", TEST_INDEX(NAME)); \
		if ((res_std > 0 && res_ft > 0) || (res_std == 0 && res_ft == 0) || (res_std < 0 && res_ft < 0)) { \
			printf("%s", SUCCESS); \
			_OK_TEST(NAME) += 1; \
		} else { \
			printf("%s (`%d` (std) != `%d` (ft))", FAIL, res_std, res_ft); \
			_FAIL_TEST(NAME) += 1; \
		} \
		printf(" `%s`\n", #FN); \
	} while (0)

/*
	Test the return value of the function. Return value are interpreted as booleans.
*/
#define TEST_RETURN_BOOL(NAME, FN) \
	do { \
		unsigned long res_std = (unsigned long) FN; \
		unsigned long res_ft = (unsigned long) ft_ ## FN; \
		printf("Test %d ", TEST_INDEX(NAME)); \
		if ((res_std && res_ft) || (!res_std && !res_ft)) { \
			printf("%s", SUCCESS); \
			_OK_TEST(NAME) += 1; \
		} else { \
			printf("%s (`%zu` (std) != `%zu` (ft))", FAIL, res_std, res_ft); \
			_FAIL_TEST(NAME) += 1; \
		} \
		printf(" `%s`\n", #FN); \
	} while (0)

/*
	Test if the return value is not null.
*/
#define TEST_RETURN_NOT_NULL(NAME, FN) \
	do { \
		unsigned long res = (unsigned long) ft_ ## FN; \
		printf("Test %d ", TEST_INDEX(NAME)); \
		if (res != 0) { \
			printf("%s", SUCCESS); \
			_OK_TEST(NAME) += 1; \
		} else { \
			printf("%s (`%zu`)", FAIL, res); \
			_FAIL_TEST(NAME) += 1; \
		} \
		printf(" `%s`\n", #FN); \
	} while(0)

/*
	Compare the value returned by the function with a `memcmp`
*/
#define TEST_RETURN_STRCMP(NAME, FN) \
	do { \
		char * res_std = (char *) FN; \
		char * res_ft = (char *) ft_ ## FN; \
		printf("Test %d ", TEST_INDEX(NAME)); \
		if ((res_std == NULL && res_ft == NULL) || strcmp(res_std, res_ft) == 0) { \
			printf("%s", SUCCESS); \
			_OK_TEST(NAME) += 1; \
		} else { \
			printf("%s (`%s` (std) != `%s` (ft))", FAIL, res_std, res_ft); \
			_FAIL_TEST(NAME) += 1; \
		} \
		printf(" `%s`\n", #FN); \
	} while(0)

/*
	Compare the value returned by the function with a `memcmp`
*/
#define TEST_RETURN_MEMCMP(NAME, FN, ARRAY, SIZE) \
	do { \
		char * res = (char *) ft_ ## FN; \
		printf("Test %d ", TEST_INDEX(NAME)); \
		if (memcmp(res, ARRAY, SIZE) == 0) { \
			printf("%s", SUCCESS); \
			_OK_TEST(NAME) += 1; \
		} else { \
			printf("%s", FAIL); \
			_FAIL_TEST(NAME) += 1; \
		} \
		printf(" `%s`\n", #FN); \
	} while(0)

/*
	Compare the value returned by the function with a `memcmp`
*/
#define TEST_MEMCMP(NAME, ARRAY1, ARRAY2, SIZE) \
	do { \
		printf("Test %d ", TEST_INDEX(NAME)); \
		if (memcmp(ARRAY1, ARRAY2, SIZE) == 0) { \
			printf("%s", SUCCESS); \
			_OK_TEST(NAME) += 1; \
		} else { \
			printf("%s", FAIL); \
			_FAIL_TEST(NAME) += 1; \
		} \
		printf("\n"); \
	} while(0)

#endif
