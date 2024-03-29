/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrito-p <mbrito-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:33:00 by mbrito-p          #+#    #+#             */
/*   Updated: 2023/08/01 00:33:00 by mbrito-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FILES
#  define MAX_FILES 500 
# endif

char	*get_next_line(int fd);
char	*ft_strchr(char *stash, int target);
char	*ft_read_line(int fd, char *stash);
char	*ft_strjoin(char *stash, char const *buf);
char	*ft_get_line(char *stash);
size_t	ft_strlen(const char *str);
char	*ft_get_new_line(char *stash);

#endif
