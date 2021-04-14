#include "header.h"
/**
 *getCommand - Search if the command exist
 *@command: The command typed for the user
 *@environ: environment
 *Return: address of the command or NULL
 */
char *getCommand(char *command, char **environ)
{
	char *path, *token, *concatanated;
	struct stat buf;
	int lenCommand, lenToken, found = 0, i;

	if (command[0] == '/')
		return (command);
	for (i = 0; environ[i]; i++)
		if (environ[i][0] == 'P' && environ[i][1] == 'A')
			path = environ[i];

	token = strtok(path, ":");
	token = strtok(NULL, ":");
	while (token != NULL)
	{
		lenToken = strlen(token);
		lenCommand = strlen(command);
		concatanated = malloc(sizeof(char) * (lenToken + lenCommand + 1));
		strcpy(concatanated, token);
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
	{
		concatanated = foundCommand(concatanated, lenCommand);
		return (concatanated);
	}
	else
	{
		printf("./hsh: No such file or directory\n");
		return (NULL);
	}
}
/**
 *foundCommand - if the command exist found the address of the command
 *@concatanated: The command typed for the user
 *@lenCommand: lenght of the command typed for the user
 *Return: address of the command
 */
char *foundCommand(char *concatanated, int lenCommand)
{
	int nDirs = 0, lenToken = 0, i;
	char *token, *nameDirs[2];

	for (i = 0; concatanated[i]; i++)
		if (concatanated[i] == '/')
			nDirs++;

	token = strtok(concatanated, "/");
	while (token != NULL)
	{
		if (nDirs == 2 || nDirs == 1)
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
