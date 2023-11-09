#include "test.h"
#include "libft_bonus.h"

void test_lstclear_bonus()
{
	START_TEST(lstclear);

	reset_memory_stats();
	t_list	*lst = malloc(sizeof(t_list));
	lst->content = malloc(1);
	lst->next = malloc(sizeof(t_list));
	lst->next->content = malloc(1);
	lst->next->next = malloc(sizeof(t_list));
	lst->next->next->content = malloc(1);
	lst->next->next->next = malloc(sizeof(t_list));
	lst->next->next->next->content = malloc(1);
	lst->next->next->next->next = NULL;

	ft_lstclear(&lst, free);
	TEST_EQ(lstclear, lst, NULL);
	CHECK_MEMORY_LEAK(lstclear);

	END_TEST(lstclear);
}
