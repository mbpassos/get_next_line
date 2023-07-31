#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char *stash, char const *buf)
{
	int		i;
	int		j;
	char	*join;

	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		stash[0] = '\0';
	}
	i = ft_strlen(stash);
	j = 0;
	join = (char *)malloc(sizeof(stash[0]) * (i + ft_strlen(buf) + 1));
	if (join == NULL)
		return (NULL);
	while (stash[j])
	{
		join[j] = stash[j];
		j++;
	}
	j = -1;
	while (buf[++j])
		join[i + j] = buf[j];
	join[i + j] = '\0';
	free(stash);
	return (join);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
