#include "libft.h"
#include "test.h"
#include "libft_bonus.h"

void test_lstadd_front_bonus()
{
	START_TEST(lstadd_front);

	// Test 1 & 2: An empty list
	t_list *list = NULL;
	t_list *new = ft_lstnew(NULL);
	ft_lstadd_front(&list, new);
	TEST_EQ(lstadd_front, list, new);
	TEST_EQ(lstadd_front, list->next, NULL);

	// Test 3 & 4: An non-empty list
	t_list *list2 = ft_lstnew(NULL);
	t_list *old2 = list2;
	t_list *new2 = ft_lstnew(NULL);
	ft_lstadd_front(&list2, new2);
	TEST_EQ(lstadd_front, list2, new2);
	TEST_EQ(lstadd_front, list2->next, old2);

	// Test 4 & 5 null parameters
	ft_lstadd_front(NULL, NULL);

	END_TEST(lstadd_front);
}
