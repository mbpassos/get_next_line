#include "get_next_line.h"

//locate character in string 
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

//attach the content from fd to the string
char	*ft_strjoin(char *stash, char const *tmp_buffer)
{
	int		i;
	int		j;
	char	*join_content_to_stash;

	if (!stash)
	{
		stash = malloc(sizeof(char) * 1); // If stash is NULL, I need to allocate memory for the NULL terminator
		stash[0] = '\0';
	}
	i = ft_strlen(stash);
	j = 0; 
	join_content_to_stash = (char *)malloc(sizeof(stash[0]) * (i + ft_strlen(tmp_buffer) + 1)); //stash[0] is the same as *stash and it means the first element of the array. I need to use stash[0] because I want to allocate memory for the first element of the array, not for the whole array. 
	if (join_content_to_stash == NULL)
		return (NULL);
	while (stash[j])
	{
		join_content_to_stash[j] = stash[j];
		j++;
	}
	j = -1; // I need to reset j to -1 because I need him to be 0 in the next line. I need it to be i + 0. Suppose: join=Hello buf =World. 
	while (tmp_buffer[++j])	//Len of join is 5, and I want to copy the position 0 of buf to the position 5 of join. Its the same of initializing j to 0, but I want to reduce 1 line of code, since the function already has 25, and with j = 0 I will have to include another one (j++) surpassing the 25 lines limit allowed by norminette.
		join_content_to_stash[i + j] = tmp_buffer[j]; // I need to increment j before using it, because I want to start from 0. I need to use i + j, because I want to start from the end of join variable, taht was copied from the stash. 
	join_content_to_stash[i + j] = '\0';
	free(stash);
	return (join_content_to_stash);
}