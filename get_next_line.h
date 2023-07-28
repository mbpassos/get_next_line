#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

char    *get_next_line(int fd);
char	*ft_strchr(char *stash, int target);
char    *ft_read_line(int fd, char *stash);
char	*ft_strjoin(char *stash, char const *tmp_buffer);
char    *ft_get_line(char *stash);

#endif

