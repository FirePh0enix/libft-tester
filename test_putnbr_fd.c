#include "libft.h"
#include "test.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define check_nbr(i, size, res) \
	do { \
		char buffer[size]; \
		memset(buffer, 0, size); \
		int fd = open("/tmp/test-putendl-fd", O_CREAT | O_RDWR); \
		ft_putnbr_fd(i, fd); \
		lseek(fd, 0, SEEK_SET); \
		read(fd, buffer, size); \
		TEST_MEMCMP(putnbr_fd, buffer, res, size); \
		close(fd); \
		remove("/tmp/test-putendl-fd"); \
	} while (0)

void test_putnbr_fd()
{
	START_TEST(putnbr_fd);
	check_nbr(0, 2, "0");
	check_nbr(-42, 4, "-42");
	check_nbr(-2147483648, 12, "-2147483648");
	check_nbr(2147483647, 11, "2147483647");
	END_TEST(putnbr_fd);
}
