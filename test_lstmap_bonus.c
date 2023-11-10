#include "test.h"
#include "libft_bonus.h"
#include <string.h>

void test_lstmap_bonus()
{
	START_TEST(lstmap);

	// Test 1-4: Duplicate strings
	t_list	*lst = malloc(sizeof(t_list));
	lst->content = "Helloworld1";
	lst->next = malloc(sizeof(t_list));
	lst->next->content = "Helloworld2";
	lst->next->next = malloc(sizeof(t_list));
	lst->next->next->content = "Helloworld3";
	lst->next->next->next = malloc(sizeof(t_list));
	lst->next->next->next->content = "Helloworld4";
	lst->next->next->next->next = NULL;

	reset_memory_stats();
	t_list *mapped_list = ft_lstmap(lst, (void *(*)(void *)) strdup, free);

	t_list *cur = mapped_list;
	int i = 0;
	char *strings[] = { "Helloworld1", "Helloworld2", "Helloworld3", "Helloworld4" };
	while (cur)
	{
		TEST_MEMCMP(lstmap, cur->content, strings[i], 12);
		cur = cur->next;
		i++;
	}

	disable_malloc();
	t_list *res = ft_lstmap(lst, (void *(*)(void *)) strdup, free);
	TEST_EQ(lstmap, res, NULL);
	enable_malloc();

	END_TEST(lstmap);
}
