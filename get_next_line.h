#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define BUFF_SIZE 1
int   get_next_line(int fd, char **line); 
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strsub(const char *s, int start, size_t size);
#endif
