#include "test.h"
#include "libft_bonus.h"
#include <string.h>

int test_count = 0;

void add_count(void *s)
{
	if (strcmp(s, "Test") == 0)
		test_count += 1;
}

void test_lstiter_bonus()
{
	START_TEST(lstiter);

	t_list	*lst = malloc(sizeof(t_list));
	lst->content = "Test";
	lst->next = malloc(sizeof(t_list));
	lst->next->content = "Hello world!";
	lst->next->next = malloc(sizeof(t_list));
	lst->next->next->content = "Test";
	lst->next->next->next = malloc(sizeof(t_list));
	lst->next->next->next->content = "Test";
	lst->next->next->next->next = NULL;

	ft_lstiter(lst, add_count);
	TEST_EQ_INT(lstiter, test_count, 3);

	END_TEST(lstiter);
}
