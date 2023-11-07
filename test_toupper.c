#include "test.h"
#include <ctype.h>

void test_toupper()
{
	START_TEST(toupper);
	TEST_RETURN(toupper, toupper('a'));
	TEST_RETURN(toupper, toupper('A'));
	TEST_RETURN(toupper, toupper('~'));
	TEST_RETURN(toupper, toupper(4523));
	END_TEST(toupper);
}
