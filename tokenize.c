#include "header.h"
/**
 *
 *
 */
void tokenize(char *line)
{
	extern char **environ;
	int status;
	pid_t son;
	char *token , *aux, *arg[1024];
	size_t i, nArgs = 1;

	for (i = 0; line[i]; i++)
	{
		if (line[i] == ' ')
			nArgs++;
	}
	line[strlen(line) - 1] = '\0';
	if (nArgs == 1)
	{
		arg[0] = getCommand(line);
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
		arg[0] = getCommand(arg[0]);
	}
	execve(arg[0], arg, environ);
}
