#include "get_next_line.h"

int		main(int ac, char **av)
{
	char	*s;
	int		fd;
	int		fd2;
	int		ret;

	ret = 1;
	if (ac == 1)
		return (0);
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	get_next_line(fd, &s);
	if (ret != -1)
		printf("%s\n", s);
	get_next_line(fd2, &s);
	if (ret != -1)
		printf("%s\n", s);
	get_next_line(fd, &s);
	if (ret != -1)
		printf("%s\n", s);
	close(fd);
	close(fd2);
	return (0);
}
