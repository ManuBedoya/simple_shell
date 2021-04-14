#include "header.h"
/**
*tokenize - separate the line typed by user an execute
*@line: line typed by user
*@environ: environment
*/
void tokenize(char *line, char environ)
{
	char *token, *arg[1024];
	size_t i, nArgs = 1;
	int value;

	for (i = 0; line[i]; i++)
	{
		if (line[i] == ' ')
			nArgs++;
	}
	line[_strlen(line) - 1] = '\0';
	if (nArgs == 1)
	{
		arg[0] = getCommand(line, environ);
	}
	else
	{
		token = strtok(line, " ");
		i = 0;
		while (token != NULL)
		{
			arg[i++] = token;
			token = strtok(NULL, " ");
		}
		arg[0] = getCommand(arg[0], environ);
	}
	value = execve(arg[0], arg, environ);
	if (value == -1)
	{
		free(arg[0]);
		exit(EXIT_FAILURE);
	}
}
