#include "headerPrintf.h"
/**
 * print_integerRecursive - makes a journey of the numbers
 * @n: is the number of the whole allocated
 * Return: 1.
 */
int print_integerRecursive(unsigned int n)
{
	unsigned int i, j;
	int count = 0;

	if (n != 0)
	{
		i = (n / 10);
		j = (n % 10);
		count += print_integerRecursive(i);
		count++;
		putchar_func(j + '0');
		return (count);
	}
	return (0);
}

/**
 * print_integer - print a integer
 * @i: integer to print
 * Return: 1.
 */
int print_integer(va_list i)
{
	int j;
	int k = 0;
	unsigned int l;

	j = va_arg(i, int);
	if (j < 0)
	{
		putchar_func('-');
		k = 1;
		l = j * -1;
	}
	else
	{
		l = j;
	}
	if (l > 9)
	{
		return (k + print_integerRecursive(l));
	}
	putchar_func(l + '0');
	return (1 + k);
}
/**
 * conversion_specifiers - convert the specifer according to the case
 * @c: is the char that specifies the case
 * @l: List characters
 * Return: NULL.
 */

int (*conversion_specifiers(const char *c, int l))(va_list)
{
	int i = 0;

	con_spe cs_arr[] = {
		{"c", sing_char},
		{"s", str_char},
		{"i", print_integer},
		{"d", print_integer},
		{NULL, NULL}};

	for (i = 0; cs_arr[i].co != NULL; i++)
	{
		if (cs_arr[i].co[0] == c[l])
		{
			return (cs_arr[i].f);
		}
	}

	return (NULL);
}
/**
 * sing_char - print single character
 * @c: is the length of the string
 * Return: Always 0.
 */

int sing_char(va_list c)
{
	char character = (char)va_arg(c, int);

	putchar_func(character);
	return (1);
}

/**
 * str_char - print a string of characters
 * @s: condition that you are going to print
 * Return: The iterator to count.
 */

int str_char(va_list s)
{
	char *string;
	int i;

	string = va_arg(s, char *);
	if (string == NULL)
	{
		string = "(null)";
	}
	for (i = 0; string[i] != '\0'; i++)
	{
		putchar_func(string[i]);
	}
	return (i);
}
