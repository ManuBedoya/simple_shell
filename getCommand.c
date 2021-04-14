#include "header.h"
/**
 *
 *
 */
char *getCommand(char *command)
{
	extern char **environ;
	char *path, *token, *concatanated;
	struct stat buf;
	int lenCommand, lenToken, found = 0, nDirs = 0;

	if (command[0] == '/')
		return (command);
	for (size_t i = 0; environ[i]; i++)
		if (environ[i][0] == 'P' && environ[i][1] == 'A')
			path = environ[i];

	token = strtok(path, ":");
	token = strtok(NULL, ":");
	while (token != NULL)
	{
		lenToken = strlen(token);
		lenCommand = strlen(command);
		concatanated = malloc(sizeof(char) * (lenToken + lenCommand + 1));
		stpcpy(concatanated, token);
		strcat(concatanated, "/");
		strcat(concatanated, command);

		if (stat(concatanated, &buf) == 0)
		{
			found = 1;
			break;
		}
		token = strtok(NULL, ":");
	}
	if (found == 1)
		return (foundCommand(concatanated, lenCommand));
	else
	{
		printf("./hsh: No such file or directory\n");
		return (NULL);
	}
}

char *foundCommand(char *concatanated, int lenCommand)
{
	int nDirs = 0, lenToken = 0;
	char *token, *nameDirs[2];


	for (int i = 0; concatanated[i]; i++)
		if (concatanated[i] == '/')
			nDirs++;

	token = strtok(concatanated, "/");
	while (token != NULL)
	{
		if (2 == nDirs || 1 == nDirs)
			nameDirs[nDirs - 1] = token;
		token = strtok(NULL, "/");
		nDirs--;
	}
	lenToken = strlen(nameDirs[0]) + strlen(nameDirs[1]);
	concatanated = malloc(sizeof(char) * lenCommand * lenToken + 2);
	concatanated[0] = '/';
	strcat(concatanated, nameDirs[1]);
	strcat(concatanated, "/");
	strcat(concatanated, nameDirs[0]);
	printf("command: %s\n", concatanated);
	return (concatanated);
}
