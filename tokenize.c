#include "header.h"
/**
*tokenize - separate the line typed by user an execute
*@line: line typed by user
*@environ: environment
*@filename: name of the file
*@iterator: counted
*/
void tokenize(char *line, char **environ, char *filename, int *iterator)
{
	char *token, *arg[1024];
	size_t i, nArgs = 1;
	int value, status;
	pid_t son;

	line[_strlen(line) - 1] = '\0';
	for (i = 0; line[i]; i++)
	{
		if (line[i] == ' ')
			nArgs++;
	}

	if (nArgs == 1)
		arg[0] = getCommand(line, environ, filename, iterator);
	else
	{
		token = strtok(line, " ");
		i = 0;
		while (token != NULL)
		{
			arg[i++] = token;
			token = strtok(NULL, " ");
		}
		arg[0] = getCommand(arg[0], environ, filename, iterator);
	}
	son = fork();
	if (son == 0)
	{
		if(arg[0] == NULL)
			exit(EXIT_FAILURE);
		value = execve(arg[0], arg, NULL);
		if (value == -1)
			exit(EXIT_FAILURE);
	}
	wait(&status);
	free(arg[0]);
}
