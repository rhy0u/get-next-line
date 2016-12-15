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
	static char	buf[BUFF_SIZE + 1];

	*line = "\0";
	next = -1;
	if(*buf)
		*line = ft_strjoin(*line, &buf[ft_is_next(buf) + 1]);
	while(((ret = read(fd, buf, BUFF_SIZE)) != -1) && (next == -1))
	{
		buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
		next = ft_is_next(buf);
	}
	*line = ft_strsub(*line, 0, ft_is_next(*line));
	if (!ret)
		return (0);
	if (!line)
		return (-1);
	return (1);
}
