/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 11:09:06 by jcentaur          #+#    #+#             */
/*   Updated: 2017/01/02 14:59:43 by jcentaur         ###   ########.fr       */
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
		(*save)->buf = "\0";
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
	while (line[i] && line[i] != '\n')
		i++;
	return (line[i]) ? i : -1;
}

int		ft_free(t_save *save, int fd)
{
	t_save *tmp;
	t_save *tmp2;

	tmp = save;
	if (!tmp)
		return (0);
	if (tmp->fd != fd)
		return (ft_free(tmp->next, fd));
	tmp2 = tmp->next;
	free(tmp->buf);
	free(tmp);
	tmp = tmp2;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	t_save			*tmp;
	static t_save	*save = NULL;

	ret = 1;
	tmp = search_fd(fd, &save);
	*line = "\0";
	*line = ft_strdup(tmp->buf);
	while (ret && get_line(*line) == -1)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1 || fd < 0)
			return (-1);
		buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	if (get_line(*line) != -1)
	{
		tmp->buf = ft_strchr(*line, '\n') + 1;
		*line = ft_strsub(*line, 0, get_line(*line));
	}
	else
		tmp->buf = "";
	if (!ret && !**line && !tmp->buf[0])
		return (0);
	return (1);
}
