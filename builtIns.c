#include "header.h"
/**
 *isBuiltIn - Search if the built-in exist and execute
 *
 *@builtin: builtin command
 *@environ: environment
 *Return: 1 if works -1 if fails
 */
int isBuiltIn(char *builtin, char **environ)
{
	int i;

	if (strlen(builtin) == 4)
	{
		if (builtin[0] == 'e' && builtin[1] == 'n' && builtin[2] == 'v')
		{
			for (i = 0; environ[i]; i++)
				printf("%s\n", environ[i]);
			return (1);
		}
	}
	if (strlen(builtin) == 5)
	{
		if (builtin[0] == 'e' && builtin[1] == 'x' && builtin[2] == 'i' &&
			builtin[3] == 't')
		{
			free(builtin);
			exit(0);
		}
	}
	return (-1);
}
