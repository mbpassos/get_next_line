/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrito-p <mbrito-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:33:38 by mbrito-p          #+#    #+#             */
/*   Updated: 2023/08/01 00:33:38 by mbrito-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strchr(char *stash, int target);
char	*ft_read_line(int fd, char *stash);
char	*ft_strjoin(char *stash, char const *t_buf);
char	*ft_get_line(char *stash);
size_t	ft_strlen(const char *str);
char	*ft_get_new_line(char *stash);

#endif
