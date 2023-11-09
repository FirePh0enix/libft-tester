#include "test.h"
#include "libft_bonus.h"
#include <string.h>

void test_lstnew_bonus()
{
	START_TEST(lstnew);

	t_list *node = ft_lstnew("Hello world");
	TEST_MEMCMP(lstnew, node->content, "Hello world", 11);
	TEST_EQ(lstnew, node->next, NULL);

	disable_malloc();
	TEST_RETURN_EQ(lstnew, ft_lstnew("Hello world"), NULL);
	enable_malloc();

	END_TEST(lstnew);
}
