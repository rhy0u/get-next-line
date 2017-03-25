/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 11:09:06 by jcentaur          #+#    #+#             */
/*   Updated: 2017/01/04 13:21:32 by jcentaur         ###   ########.fr       */
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
		(*save)->buf = NULL;
		(*save)->next = NULL;
	}
	if ((*save)->fd == fd)
		return (*save);
	return (search_fd(fd, &((*save)->next)));
}

int		get_line(char *s)
{
	int i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] && s[i] != '\n' && s[i] != '\r')
		i++;
	return (s[i]) ? i : -1;
}

void	ft_cheat(char **line, t_save *tmp, char **test)
{
	int		r;

	r = get_line(*test);
	if (r != -1)
	{
		tmp->buf = ft_strsub(*test, r + 1,
			ft_strlen(*test) - (r + 1));
		*line = ft_strsub(*test, 0, r);
		ft_strdel(test);
	}
	else
	{
		*line = ft_strdup(*test);
		ft_strdel(test);
		tmp->buf = NULL;
	}
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	t_save			*tmp;
	char			*test;
	static t_save	*save = NULL;

	if (!line || fd < 0)
		return (-1);
	tmp = search_fd(fd, &save);
	test = NULL;
	if (tmp->buf)
	{
		test = ft_strdup(tmp->buf);
		free(tmp->buf);
	}
	ret = 1;
	while (ret && get_line(test) == -1)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		test = ft_strjoinf(test, buf);
	}
	ft_cheat(line, tmp, &test);
	return ((!ret && !**line && !tmp->buf) ? 0 : 1);
}
