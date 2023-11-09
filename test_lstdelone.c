#include "libft.h"
#include "test.h"

void test_lstdelone()
{
	START_TEST(lstdelone);

	reset_memory_stats();
	t_list *lst = malloc(sizeof(t_list));
	lst->content = malloc(1);
	ft_lstdelone(lst, free);
	CHECK_MEMORY_LEAK(lstdelone);

	lst = malloc(sizeof(t_list));
	lst->content = malloc(1);
	ft_lstdelone(NULL, free);
	ft_lstdelone(lst, NULL);

	END_TEST(lstdelone);
}
