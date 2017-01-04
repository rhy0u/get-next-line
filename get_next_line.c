/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 11:09:06 by jcentaur          #+#    #+#             */
/*   Updated: 2017/01/04 14:00:02 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_save	*search_fd(int fd, t_save **save)
{
	if (!*save)
	{
		if (!(*save = (t_save*)malloc(sizeof(t_save))))
			return (NULL);
		(*save)->fd = fd;
		(*save)->buf = "";
		(*save)->next = NULL;
	}
	if ((*save)->fd == fd)
		return (*save);
	return (search_fd(fd, &((*save)->next)));
}

int		get_line(char *line)
{
	int i;

	if (!line)
		return (-1);
	i = 0;
	while (line[i] && line[i] != '\n' && line[i] != '\r')
		i++;
	return (line[i]) ? i : -1;
}

void	ft_cheat(char **line, t_save *tmp)
{
	int		r;

	r = get_line(*line);
	if (get_line(*line) != -1)
	{
		tmp->buf = ft_strsub(*line, get_line(*line) + 1,
			ft_strlen(*line) - get_line(*line) - 1);
		*line = ft_strsub(*line, 0, get_line(*line));
	}
	else
		tmp->buf = "";
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	t_save			*tmp;
	static t_save	*save = NULL;

	if (!line || fd < 0)
		return (-1);
	tmp = search_fd(fd, &save);
	*line = ft_strdup(tmp->buf);
	ret = 1;
	while (ret && get_line(*line) == -1)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		*line = ft_strjoinf(*line, buf);
	}
	ft_cheat(line, tmp);
	return ((!ret && !**line && !tmp->buf[0]) ? 0 : 1);
}
