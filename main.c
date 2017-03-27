/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 08:10:17 by jcentaur          #+#    #+#             */
/*   Updated: 2017/03/27 09:06:20 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		ret, fd, fd2;
	char	*s;

	if (ac != 3)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (0);
	if ((fd2 = open(av[2], O_RDONLY)) < 0)
		return (0);
	get_next_line(fd , &s);
	printf("%s\n", s);
	free(s);
	get_next_line(fd , &s);
	printf("%s\n", s);
	free(s);
	while ((ret = get_next_line(fd, &s)) && ret != -1)
	{
		printf("%s\n", s);
		free(s);
	}
	free(s);
	while ((ret = get_next_line(fd2, &s)) && ret != -1)
	{
		printf("%s\n", s);
		free(s);
	}
	free(s);
	close(fd);
	close(fd2);
	while (1);
	return (0);
}
