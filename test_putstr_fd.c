#include "libft.h"
#include "test.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

void test_putstr_fd()
{
	START_TEST(putstr_fd);

	char buffer[13];
	buffer[12] = '\0';
	int fd = open("/tmp/test-putstr-fd", O_CREAT | O_RDWR);

	ft_putstr_fd("Hello world!", fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, buffer, 13);
	TEST_MEMCMP(putstr_fd, buffer, "Hello world!", 13);

	close(fd);
	remove("/tmp/test-putstr-fd");

	END_TEST(putstr_fd);
}
