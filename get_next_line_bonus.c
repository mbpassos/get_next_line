#include "get_next_line_bonus.h"

char    *ft_read_line(int fd, char *stash)
{
    int     number_of_bytes_read;
    char    *tmp_buffer;

    tmp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1)); //Allocate memory for the temporary buffer
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
        stash = ft_strjoin(stash, tmp_buffer); //append buffer to stash
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
    i = 0;
    while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i]; //Copy characters from stash to the line
		i++;
	}
    if (stash[i] == '\n')
    {
        line[i++] = '\n'; //Append the newline character if present
    }        
	line[i] = '\0'; //Null-terminate the line
	return (line);    
}

//ft_new_line function extracts the remaining data from the stash after 
//the newline character. So get_line will read and store the data before \n, 
//and New_Line will do it after the \n.
//It searches for the newline character in the stash and determines the 
//remaining length of the stash after the newline.
char    *ft_get_new_line(char *stash)
{
    int i;
    int j;
    char    *newline; //remaining data on stash after the newline character

    i = 0,
    j = 0;
    while(stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
    {
        free(stash);
        return (NULL);
    }
    newline = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1)); //Allocate memory fo the remaining stash after the newline character
    if (!newline)
        return (NULL);
    i++;
    while (stash[i])
        newline[j++] = stash[i++]; //Copy remaining characters from stash to the new string
    newline[j] = '\0';
    free(stash);
    return(newline);
}


char	*get_next_line(int fd)
{
	char    *line;
    static char	*stash[MAX_FILES]; //static array of char pointers (strins) named stash and its size is MAX_FILES. 

    if (fd < 0 || fd > MAX_FILES || BUFFER_SIZE <= 0) // the first difference between mandatory and bonus is MAX_FILES (which is the max number of files that can be opened at the same time: 256). Prefefined in the header file as 500
        return (NULL);	
    stash [fd] = ft_read_line(fd, stash[fd]); // the second difference is that I'm using fd position [fd] to store the stash of each file.this memorizes the line read from the file before passing to the new file to read (if there is one)
    // 3rd difference is in the definition of the amount of files to read in the header file.
    if (!stash[fd])				
		return (NULL);
    line = ft_get_line(stash[fd]);
    stash[fd] = ft_get_new_line(stash[fd]);
    return (line);
}