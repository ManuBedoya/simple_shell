#include "header.h"
/**
 *main - entry point
 *Return: 0 always
 *@argc: Number of arguments
 */
int main(int argc)
{
	(void)argc;

	if (argc == 1)
		interactiveMode();

	else
		non_interactive();
	return (0);
}
