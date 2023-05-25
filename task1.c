#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * main - Entry point of the simple shell program
 *
 * Description: This program creates a simple UNIX command line interpreter.
 * It displays a prompt, waits for the user to type a command, and executes it.
 * The command lines are single words with no arguments or special characters.
 * It handles errors, including the "end of file" condition.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char *inputBuffer;        /* Buffer to store user input */
ssize_t readChars;        /* Number of characters read */
size_t bufferSize = BUFFER_SIZE;   /* Size of the input buffer */

inputBuffer = malloc(bufferSize);  /* Allocate memory for input buffer */
if (inputBuffer == NULL)
{
perror("Error: Unable to allocate inputBuffer");
exit(EXIT_FAILURE);
}

while (1)
{
printf("$ ");  /* Display the prompt */
readChars = getline(&inputBuffer, &bufferSize, stdin);
if (readChars == -1)  /* Handle "end of file" condition */
{
printf("\n");
break;
}

/* TODO: Handle command execution */

}

free(inputBuffer);  /* Free allocated memory */
return (0);
}
