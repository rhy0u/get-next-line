#include "get_next_line.h"

int		main(int ac, char **av)
{
	char	*s;
	int		fd;
	int		ret;

	ret = 1;
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while(ret != 0 && ret != -1)
	{
		ret = get_next_line(fd, &s);
		if (ret != 0 && ret != -1)
			printf("%s\n", s);
		usleep(250000);
	}
	close(fd);
	return (0);
}
