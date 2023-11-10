#include "test.h"
#include <stdlib.h>
#include <string.h>

void test_calloc()
{
	START_TEST(calloc);

	TEST_RETURN_NOT_NULL(calloc, calloc(1, 8));
	TEST_RETURN_NOT_NULL(calloc, calloc(0, 8));
	TEST_RETURN(calloc, calloc(-5, -5), "Overflow is not handled correctly");
	TEST_RETURN_NOT_NULL(calloc, calloc(0, -5));
	TEST_RETURN_NOT_NULL(calloc, calloc(-5, 0));
	TEST_RETURN_NOT_NULL(calloc, calloc(0, 0));

	char tab[20];
	memset(tab, 0, 20);
	TEST_RETURN_MEMCMP(calloc, calloc(1, 20), tab, 20);

	END_TEST(calloc);
}
