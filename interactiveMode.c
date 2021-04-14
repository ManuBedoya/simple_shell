#include "header.h"
/**
 *interactiveMode - Start the infinite loop to display the prompt
 *@environ: environment
 *@filename: name of the file
 */
void interactiveMode(char **environ, char *filename)
{
	char *line, *prompt = "$ ";
	size_t lineSize;
	int value, status, iterator;
	pid_t son;

	while (1)
	{
		line = NULL;
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		value = getline(&line, &lineSize, stdin);
		if (value == EOF)
		{
			free(line);
			exit(0);
		}
		iterator++;
		if (isBuiltIn(line, environ) == -1)
		{
			son = fork();
			if (son == 0)
				tokenize(line, environ, filename, iterator);
			else if (son > 0)
				wait(&status);
			else
				printf("error");
		}
		free(line);
	}
}
