#include "get_next_line.h"

int		main(int ac, char **av)
{
	char	*s;
	int		fd;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while(get_next_line(fd, &s))
		printf("%s\n", s);
	close(fd);
	return (0);
}
