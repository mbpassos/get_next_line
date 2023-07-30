#include "get_next_line.h"

// int	main(void)
// {
//     int fd;
//     char *line;

//     fd = open("example.txt", O_RDONLY); // Open the file for reading
//     if (fd == -1)
//     {
//         // Handle file opening error
//         return (1);
//     }

//     while ((line = get_next_line(fd)) != NULL)
// 	// Call get_next_line in a loop until it returns NULL
//     {
//         // Process the line (e.g., print it)
//         printf("%s\n", line);

//         free(line); // Free the memory allocated for the line
//     }

//     close(fd); // Close the file

//     return (0);
// }

int main(void)
{
    int fd1, fd2;
    char *line;

    fd1 = open("file1.txt", O_RDONLY); // Open file1 for reading
    fd2 = open("file2.txt", O_RDONLY); // Open file2 for reading

    if (fd1 == -1 || fd2 == -1)
    {
        perror("Error opening file");
        return 1;
    }

    // Reading lines from file1
    printf("Reading lines from file1:\n");
    while ((line = get_next_line(fd1)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    // Reading lines from file2
    printf("\nReading lines from file2:\n");
    while ((line = get_next_line(fd2)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd1); // Close file1
    close(fd2); // Close file2

    return 0;
}



// de repente introduzir algo no loop pra mostrar que le lina a linha: tipo:
   
//     while ((line = get_next_line(fd1)) != NULL)
//     {
//         printf("linha lida:\n");
//         printf("%s\n", line);
//         free(line);
//     }


// FOR BONUS
/* int main(void)
{
	int fd1, fd2, fd3;
	char *line;

	// Abrir os arquivos de texto
	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);

	// Ler linhas do primeiro arquivo
	line = get_next_line(fd1);
	while (line != NULL)
	{
		printf("File 1: %s\n", line);
		free(line);
		line = get_next_line(fd1);
	}

	// Ler linhas do segundo arquivo
	line = get_next_line(fd2);
	while (line != NULL)
	{
		printf("File 2: %s\n", line);
		free(line);
		line = get_next_line(fd2);
	}

	// Ler linhas do terceiro arquivo
	line = get_next_line(fd3);
	while (line != NULL)
	{
		printf("File 3: %s\n", line);
		free(line);
		line = get_next_line(fd3);
	}

	// Fechar os arquivos
	close(fd1);
	close(fd2);
	close(fd3);

	return 0;
}
 */