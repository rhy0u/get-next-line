/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 14:17:36 by jcentaur          #+#    #+#             */
/*   Updated: 2017/01/02 14:52:31 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (get_next_line(fd, &s))
	{
		printf("%s\n", s);
		usleep(250000);
	}
	close(fd);
	return (0);
}
