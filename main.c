// #include "get_next_line_bonus.h"
// #include "get_next_line.h"

// FOR MANDATORY PART
// int main(void)
// {
//     int fd1, fd2;
//     char *line;
//     fd1 = open("file1.txt", O_RDONLY); // Open file1 for reading
//     fd2 = open("file2.txt", O_RDONLY); // Open file2 for reading
//     if (fd1 == -1 || fd2 == -1)
//     {
//         perror("Error opening file");
//         return 1;
//     }
//     // Reading lines from file1
//     printf("Reading lines from file1:\n");
//     while ((line = get_next_line(fd1)) != NULL)
//     {
//         printf("File 1 line: %s\n", line);
//         free(line);
//     }
//     // Reading lines from file2
//     printf("\nReading lines from file2:\n");
//     while ((line = get_next_line(fd2)) != NULL)
//     {
//         printf("File 2 line: %s\n", line);
//         free(line);
//     }
//     close(fd1); // Close file1
//     close(fd2); // Close file2
//     return 0;
// }

// FOR BONUS
// int main(void)
// {
// 	int fd1, fd2, fd3;
// 	char *line;
// 	// Abrir os arquivos de texto
// 	fd1 = open("file1.txt", O_RDONLY);
// 	fd2 = open("file2.txt", O_RDONLY);
// 	fd3 = open("file3.txt", O_RDONLY);
// 	// Ler linhas do primeiro arquivo
// 	line = get_next_line(fd1);
// 	while (line != NULL)
// 	{
// 		printf("File 1: %s\n", line);
// 		free(line);
// 		line = get_next_line(fd1);
// 	}
// 	// Ler linhas do segundo arquivo
// 	line = get_next_line(fd2);
// 	while (line != NULL)
// 	{
// 		printf("File 2: %s\n", line);
// 		free(line);
// 		line = get_next_line(fd2);
// 	}
// 	// Ler linhas do terceiro arquivo
// 	line = get_next_line(fd3);
// 	while (line != NULL)
// 	{
// 		printf("File 3: %s\n", line);
// 		free(line);
// 		line = get_next_line(fd3);
// 	}
// 	// Fechar os arquivos
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return 0;
// }

// TO SHOW DIFFERENCES BETWEEN FUNCTIONS
// int main(void) {
//     int fd1, fd2;
//     char *line;
    
//     // Open the first file
//     fd1 = open("file1.txt", O_RDONLY);
//     if (fd1 < 0) {
//         perror("Error opening file1.txt");
//         return 0;
//     }
    
//     // Open the second file
//     fd2 = open("file2.txt", O_RDONLY);
//     if (fd2 < 0) {
//         perror("Error opening file2.txt");
//         return 0;
//     }
    
//     printf("Reading from file1.txt and file2.txt using get_next_line_bonus:\n");
    
//     // Continue reading until both files have reached the end
//     while (1) {
//         line = get_next_line(fd1);
//         if (line) {
//             printf("[%d] %s\n", fd1, line);
//             free(line);
//         }
//         else {
//             // File 1 has reached the end or an error occurred
//             close(fd1);
//             fd1 = -1; // Mark as closed
//         }
        
//         line = get_next_line(fd2);
//         if (line) {
//             printf("[%d] %s\n", fd2, line);
//             free(line);
//         }
//         else {
//             // File 2 has reached the end or an error occurred
//             close(fd2);
//             fd2 = -1; // Mark as closed
//         }
        
//         // Break the loop if both files have reached the end
//         if (fd1 == -1 && fd2 == -1) {
//             break;
//         }
//     }
    
//     return 0;
// }