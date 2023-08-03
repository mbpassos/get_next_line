/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrito-p <mbrito-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:33:22 by mbrito-p          #+#    #+#             */
/*   Updated: 2023/08/02 23:06:42 by mbrito-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *stash, int target)
{
	int	i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i])
	{
		if ((unsigned char)stash[i] == (unsigned char)target)
			return (&stash[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *stash, char const *t_buf)
{
	int		i;
	int		j;
	char	*j_stash;

	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		stash[0] = '\0';
	}
	i = ft_strlen(stash);
	j = 0;
	j_stash = (char *)malloc(sizeof(stash[0]) * (i + ft_strlen(t_buf) + 1));
	if (j_stash == NULL)
		return (NULL);
	while (stash[j])
	{
		j_stash[j] = stash[j];
		j++;
	}
	j = -1;
	while (t_buf[++j])
		j_stash[i + j] = t_buf[j];
	j_stash[i + j] = '\0';
	free(stash);
	return (j_stash);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
