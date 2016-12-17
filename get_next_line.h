/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:44:26 by jcentaur          #+#    #+#             */
/*   Updated: 2016/12/16 17:44:29 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# define BUFF_SIZE 1
int   get_next_line(int fd, char **line);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strsub(const char *s, int start, size_t size);
size_t	ft_strlen(const char *s);
#endif
