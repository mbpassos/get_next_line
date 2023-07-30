#include "get_next_line.h"

//reads function reads data from the file descriptor (fd) into 
//a temporary buffer(buf),and appends it to the existing string that 
//accumulates what its read (stash) until a newline character is encountered
//or the end of file is reached.
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

//get_next_line function is the entry point for retrieving lines from a file.
//It takes a file descriptor (fd) as an argument.
//The function checks if the file descriptor is valid and if the buffer size 
//is positive.It calls ft_read_line to read data from the file into the stash.
//Then, it calls ft_get_line to extract a line from the stash. Finally,
//it calls ft_new_line to extract the remaining data after the line from the 
//stash.The function returns the extracted line. It repeats the process of 
//reading lines from a file by utilizing a static buffer to store the data 
//between function calls.
char    *get_next_line(int  fd)
{
    char    *line; //line returned in the function
    static char *stash; //static variable allows to store data bwtween function calls;

    if (fd < 0 || BUFFER_SIZE <= 0) //Check if file descriptor is valid and buffer size is positive
        return (0);
    stash = ft_read_line(fd, stash); //Read data from the file and update the stash
    if (!stash)
        return (NULL);
    line = ft_get_line(stash); //extract a line from the stash
    stash = ft_get_new_line(stash); //extract remaining data after the newline character
    return (line);    
}