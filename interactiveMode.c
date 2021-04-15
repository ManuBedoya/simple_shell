#include "header.h"
/**
 *interactiveMode - Start the infinite loop to display the prompt
 *@environ: environment
 *@filename: name of the file
 */
void interactiveMode(char **environ, char *filename)
{
	char *line = NULL;
	size_t lineSize;
	int iterator = 0;

	while (1)
	{
		line = NULL;
		if (isatty(0) == 1)
			_printf("$ ");
		if (getline(&line, &lineSize, stdin) == EOF)
		{
			free(line);
			exit(0);
		}
		iterator++;
		if (isBuiltIn(line, environ) == -1)
			tokenize(line, environ, filename, &iterator);
		free(line);
	}
}
