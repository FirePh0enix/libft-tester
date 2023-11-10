#include "libft.h"
#include "test.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

void test_putendl_fd()
{
	START_TEST(putendl_fd);

	char buffer[14];
	buffer[13] = '\0';
	int fd = open("/tmp/test-putendl-fd", O_CREAT | O_RDWR);

	ft_putendl_fd("Hello world!", fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, buffer, 14);
	TEST_MEMCMP(putendl_fd, buffer, "Hello world!\n", 14);

	close(fd);
	remove("/tmp/test-putendl-fd");

	END_TEST(putendl_fd);
}
