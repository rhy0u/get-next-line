#include "get_next_line.h"

int		main(int ac, char **av)
{
	char	*s;
	int		fd;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &s);
	printf("%s", s);
	return (0);
}
