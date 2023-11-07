#include "test/test.h"
#include <stdio.h>
#include <stdlib.h>

void test_atoi()
{
	START_TEST(atoi);
	TEST_RETURN(atoi, atoi("42"));
	TEST_RETURN(atoi, atoi("-42"));
	TEST_RETURN(atoi, atoi("2a"));
	TEST_RETURN(atoi, atoi("--123"));
	TEST_RETURN(atoi, atoi(""));
	//TEST_RETURN(atoi, atoi(NULL)); Segfault
	END_TEST(atoi);
}
