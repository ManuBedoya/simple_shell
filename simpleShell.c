#include "header.h"
/**
 *main - entry point
 *Return: 0 always
 *@argc: Number of arguments
 *@argv: Array of Arguments
 *@environ: environment
 */
int main(int argc, char *argv[], char **environ)
{
	(void)argv;

	if (argc == 1)
		interactiveMode(environ);
	return (0);
}
