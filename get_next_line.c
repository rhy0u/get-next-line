#include "get_next_line.h"

t_save	*search_fd(int fd, t_save **save)
{
	if (!*save)
		if(!(*save = (t_save *)malloc(sizeof(t_save))))
			return (NULL);
		return (*save);
	if ((*save)->fd == fd)
		return (*save);
	return (search_fd(fd, &(*save)->next));
}

int		get_line(char **line)
{
	int i;



int		get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	t_save			*to_read;
	static t_save	*save = NULL;

	ret = 1;

	if (fd < 0)
		return (-1);
	to_read = search_fd(fd, &save);
	while (ret != -1 && ret)
	{
		ret = read(fd, buf, BUFF_SIZE);
		to_read->buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
	}

	


}
