#include "test.h"

void test_lstsize()
{
	START_TEST(lstsize);

	t_list	*lst = malloc(sizeof(t_list));
	lst->next = malloc(sizeof(t_list));
	lst->next->next = malloc(sizeof(t_list));
	lst->next->next->next = malloc(sizeof(t_list));
	lst->next->next->next->next = NULL;

	TEST_RETURN_EQ(lstsize, ft_lstsize(lst), 4);
	TEST_RETURN_EQ(lstsize, ft_lstsize(NULL), 0);

	END_TEST(lstsize);
}
