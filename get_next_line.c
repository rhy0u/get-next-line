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
	int			next;
	int			ret;
	char		*tmp;
	static char	*buf;

	*line = "\0";
	next = 0;
	tmp = ft_strjoin(*line, buf);
	while((ret = read(fd, buf, BUFF_SIZE)) && !next)
	{
		buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
		if(ft_is_next(buf) >= 0)
		{
			next = 1;
			buf += ft_is_next(buf) + 1;
		}
	}
	*line = ft_strsub(*line, 0, ft_is_next(*line));
	if (!ret)
		return (0);
	if (!line)
		return (-1);
	return (1);
}
