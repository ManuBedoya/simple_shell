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
	if (argc == 1)
		interactiveMode(environ, argv[0]);
	return (0);
}
