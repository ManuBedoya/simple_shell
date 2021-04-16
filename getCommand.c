#include "header.h"
/**
 *getCommand - Search if the command exist
 *@command: The command typed for the user
 *@environ: environment
 *@filename: name of the file
 *@iterator: Counted
 *Return: address of the command or NULL
 */
char *getCommand(char *command, char **environ, char *filename, int *iterator)
{
	char path[3000], *token, *concatanated;
	struct stat buf;
	int lenCommand, lenToken, found = 0, i, j;

	for (i = 0; environ[i]; i++)
		if (environ[i][0] == 'P' && environ[i][1] == 'A')
			for (j = 0; environ[i][j]; j++)
				path[j] = environ[i][j];
	token = strtok(path, ":");
	while (token != NULL)
	{
		lenToken = _strlen(token);
		lenCommand = _strlen(command);
		concatanated = malloc(sizeof(char) * (lenToken + lenCommand + 2));
		*concatanated = '\0';
		if (command[0] != '/')
		{
			_strcat(concatanated, token);
			_strcat(concatanated, "/");
			_strcat(concatanated, command);
		}
		else
			_strcat(concatanated, command);
		if (stat(concatanated, &buf) == 0)
		{
			found = 1;
			break;
		}
		token = strtok(NULL, ":");
		free(concatanated);
	}
	if (found == 1)
		return (concatanated);
	_printf("%s: %i: %s: not found\n", filename, *iterator, command);
	return (NULL);
}
