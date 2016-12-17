/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:53:20 by jcentaur          #+#    #+#             */
/*   Updated: 2016/12/16 17:15:48 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_is_next(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	int				next;
	int				ret;
	static char		*tmp = "\0";
	char			buf[BUFF_SIZE + 1];

	*line = "\0";
	next = -1;
	ret = 1;
	*line = ft_strjoin(tmp, *line);
	if (ft_is_next(*line) != -1)
	{
		*line = ft_strsub(*line, 0, ft_is_next(*line));
		tmp = ft_strsub(tmp, ft_is_next(tmp) + 1,
			ft_strlen(tmp) - ft_is_next(tmp) - 1);
		if (!**line)
			return(-1);
		if (!*tmp)
			return (0);
		return (1);
	}
	while (next == -1 && ret != 0 && ret != -1)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
		next = ft_is_next(buf);
	}
	tmp = ft_strsub(*line, ft_is_next(*line) + 1,
		ft_strlen(*line) - ft_is_next(*line) - 1);
	*line = ft_strsub(*line, 0, ft_is_next(*line));
	if (!ret)
		return (0);
	if (!line)
		return (-1);
	return (1);
}
