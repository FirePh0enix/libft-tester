#include "test.h"
#include <string.h>

void test_strchr()
{
	START_TEST(strchr);
	TEST_RETURN_STRCMP(strchr, strchr("Hello world!", 'w'));
	TEST_RETURN_STRCMP(strchr, strchr("Hello world!", 'z'));
	TEST_RETURN_STRCMP(strchr, strchr("Hello world!", '\0'));
	TEST_RETURN_STRCMP(strchr, strchr("", 'w'));
	TEST_RETURN_STRCMP(strchr, strchr("", '\0'));
	TEST_RETURN_STRCMP(strchr, strchr("", ' '));
	TEST_RETURN_STRCMP(strchr, strchr("G4NGPL4NK B3ST CH4MP", ' '));
	TEST_RETURN_STRCMP(strchr, strchr("G4NGPL4NK B3ST CH4MP", 'V'));
	TEST_RETURN_STRCMP(strchr, strchr("G4NGPL4NK B3ST CH4MP", '\0'));
	TEST_RETURN_STRCMP(strchr, strchr("G4NGPL4NK B3ST CH4MP", '32'));
	TEST_RETURN_STRCMP(strchr, strchr("\0", 'c'));
	TEST_RETURN_STRCMP(strchr, strchr("\0", '\0'));
	TEST_RETURN_STRCMP(strchr, strchr("EZ", '3'));

	END_TEST(strchr);
}
