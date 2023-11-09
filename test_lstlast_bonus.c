#include "test.h"
#include "libft_bonus.h"

void test_lstlast_bonus()
{
	START_TEST(lstlast);

	t_list	*lst = malloc(sizeof(t_list));
	lst->next = malloc(sizeof(t_list));
	lst->next->next = malloc(sizeof(t_list));
	lst->next->next->next = malloc(sizeof(t_list));
	lst->next->next->next->next = NULL;
	TEST_RETURN_EQ(lstlast, ft_lstlast(lst), lst->next->next->next);
	TEST_RETURN_EQ(lstlast, ft_lstlast(NULL), NULL);

	END_TEST(lstlast);
}
