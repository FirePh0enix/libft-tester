#include "libft.h"
#include "test.h"
#include <string.h>

void test_split()
{
	START_TEST(split);

	char *table[] = { "This", "is", "a", "test" };
	TEST_RETURN_STRCMP_ARRAY(split, ft_split("This is a test", ' '), table, 4);

	char *table2[] = { "This is a test" };
	TEST_RETURN_STRCMP_ARRAY(split, ft_split("This is a test", '\n'), table2, 1);

	char *table3[] = { "G4NGPL4NK", "B3ST", "CH4MP"};
	TEST_RETURN_STRCMP_ARRAY(split, ft_split("G4NGPL4NK B3ST CH4MP", ' '), table3, 3);

	char *table4[] = {"G4NGPL4NKB3STCH4MP"};
	TEST_RETURN_STRCMP_ARRAY(split, ft_split("G4NGPL4NKB3STCH4MP", ' '), table4, 1);

	char *table5[] = {"G4NGPL4NKB3STCH4MP"};
	TEST_RETURN_STRCMP_ARRAY(split, ft_split("G4NGPL4NKB3STCH4MP", '\0'), table5, 1);
	
	char *table6[] = {"G4NG", "PL4NK", "B3STCH4MP"};
	TEST_RETURN_STRCMP_ARRAY(split, ft_split("G4NG7PL4NK7B3STCH4MP", '7'), table6, 3);

	char *table7[] = {""};
	TEST_RETURN_STRCMP_ARRAY(split, ft_split("", '\0'), table7, 0);

	char *table8[] = {"7", "5", "4", "2"};
	TEST_RETURN_STRCMP_ARRAY(split, ft_split("7+++5++4++++++++++++++2", '+'), table8, 4);
	END_TEST(split);
}
