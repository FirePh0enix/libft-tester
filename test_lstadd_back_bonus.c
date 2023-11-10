#include "test.h"
#include "libft_bonus.h"

void test_lstadd_back_bonus()
{
	START_TEST(lstadd_back);

	// Test 1 & 2: An empty list
	t_list *list = NULL;
	t_list *new = calloc(1, sizeof(t_list));
	ft_lstadd_back(&list, new);
	TEST_EQ(lstadd_back, list, new);
	TEST_EQ(lstadd_back, list->next, NULL);

	// Test 3 & 4: An non-empty list
	t_list *list2 = calloc(1, sizeof(t_list));
	t_list *old2 = list2;
	t_list *new2 = calloc(1, sizeof(t_list));
	ft_lstadd_back(&list2, new2);
	TEST_EQ(lstadd_back, list2->next, new2);
	TEST_EQ(lstadd_back, list2, old2);

	// Test 4 & 5 null parameters
	ft_lstadd_back(NULL, NULL);

	END_TEST(lstadd_back);
}
