#include "get_next_line.h"

//reads function reads data from the file descriptor (fd) into 
//a temporary buffer(buf),and appends it to the existing string that 
//accumulates what its read (stash) until a newline character is encountered
//or the end of file is reached.
char    *ft_read_line(int fd, char *stash)
{
    int     number_of_bytes_read;
    char    *tmp_buffer;

    tmp_buffer = malloc(sizeof(char*) * (BUFER_SIZE + 1));
    if(!tmp_buffer)
        return (NULL);

    number_of_bytes_read = 1; //to force entry in the while loop at least one time and check for empty files
    while(!ft_strchr(stash, '\n') && number_of_bytes_read != 0) //read until newline is found or end of file is reached
    {
        number_of_bytes_read = read(fd, tmp_buffer, BUFFER_SIZE);
        if (number_of_bytes_read == -1) //checks for errors
        {
            free(tmp_buffer);
            free(stash);
            return (NULL);
        }   
        tmp_buffer[number_of_bytes_read] = '\0'; 
        if(!tmp_buffer)
            return (NULL);
        stash = ft_strjoin(stash, tmp_buffer);
    }
    free(tmp_buffer);
    return (stash);
}

//ft_get_line function extracts a line from the provided stash until a 
//newline character ('\n') or the end of the buffer is encountered.
char    *ft_get_line(char *stash)
{
    int i;
    char    *line;

    i = 0;
    if (!stash[i])
        return (NULL);
    while(stash[i] && stash[i] != '\n') //checks if stash exists or if it reached the end of the current line
        i++;
    if (stash[i] == '\0') //when the newline character ('\n') is not present in the stash indicating that the extracted line reaches the end of the stash string.
        line = (char *)malloc(sizeof(char) * (i + 1)); //the memory allocation is i + 1 to accommodate the characters in the line and the null-terminating character ('\0').
    else // This line is executed when the newline character is present in the stash, indicating that the extracted line is not the last line in the stash and there are more characters after the newline. 
        line = (char *)malloc(sizeof(char) * (i + 2)); //In this case, the memory allocation is i + 2 to accommodate the characters in the line, the newline character ('\n'), and the null-terminating character ('\0').
    if (!line)
        return (NULL);
    while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i]; // Line 16 - Copy characters from stash to the line
		i++;
	}
    if (stash[i] == '\n')
    {
        line[i] = '\n'; // Line 21 - Append the newline character if present
        i++;
    }		
	line[i] = '\0'; // Line 22 - Null-terminate the line
	return (line);    
}