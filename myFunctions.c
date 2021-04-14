#include "header.h"
/**
 * _strlen - calcuate the lenght of a string
 * @s: Array of strings
 * Return: a length of *s
*/
int _strlen(char *s)
{
	int count = 0;

	while (s[count] != 0)
		count++;
	return (count);
}
/**
 * *_strcat - concatenates 2 strings
 * @src: String
 * @dest: String
 *
 * Return: String concatanate
 *
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i]; i++)
	{
	}

	for (j = 0; src[j]; j++, i++)
		dest[i] = src[j];
	return (dest);
}
/**
 * *_strcpy - Copie a pointer to another ponter
 * @dest: destinity
 * @src: Origen
 * Return: character
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (i < _strlen(src))
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
