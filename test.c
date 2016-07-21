#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
main()
{
	int ret,fd;

	fd = open("/dev/sx_ccore", O_RDWR);

	close(fd);
}
