#include "libft.h"
#include "test.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

void test_putchar_fd()
{
	START_TEST(putchar_fd);

	char c;
	int fd = open("/tmp/test-putchar-fd", O_CREAT | O_RDWR);

	ft_putchar_fd('Z', fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, &c, 1);
	TEST_EQ_INT(putchar_fd, c, 'Z');

	close(fd);
	remove("/tmp/test-putchar-fd");

	END_TEST(putchar_fd);
}
