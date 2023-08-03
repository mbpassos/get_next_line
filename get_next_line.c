
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrito-p <mbrito-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:33:31 by mbrito-p          #+#    #+#             */
/*   Updated: 2023/08/01 00:33:31 by mbrito-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *stash)
{
	int			number_of_bytes_read;
	char		*tmp_buffer;

	tmp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_buffer)
		return (NULL);
	number_of_bytes_read = 1;
	while (!ft_strchr(stash, '\n') && number_of_bytes_read != 0)
	{
		number_of_bytes_read = read(fd, tmp_buffer, BUFFER_SIZE);
		if (number_of_bytes_read == -1)
		{
			free(tmp_buffer);
			free(stash);
			return (NULL);
		}
		tmp_buffer[number_of_bytes_read] = '\0';
		if (!tmp_buffer)
			return (NULL);
		stash = ft_strjoin(stash, tmp_buffer);
	}
	free(tmp_buffer);
	return (stash);
}

char	*ft_get_line(char *stash)
{
	int			i;
	char		*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		line = (char *)malloc(sizeof(char) * (i + 1));
	else
		line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_new_line(char *stash)
{
	int		i;
	int		j;
	char	*newline;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	newline = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!newline)
		return (NULL);
	i++;
	while (stash[i])
		newline[j++] = stash[i++];
	newline[j] = '\0';
	free(stash);
	return (newline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_get_new_line(stash);
	return (line);
}
