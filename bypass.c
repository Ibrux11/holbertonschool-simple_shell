#include "shell.h"

/**
 * _strcat - Concatenates two strings
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: Integer value representing the comparison result
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, val;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	val = s1[i] - s2[i];

	return (val);
}

/**
 * _strlen - Calculates the length of a string
 * @s: Input string
 *
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strncmp - Compares two strings up to a given number of characters
 * @s1: First string
 * @s2: Second string
 * @n: Number of characters to compare
 *
 * Return: Difference between the first differing characters
 */
size_t _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] != '\0' && i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}

	return (0);
}

/**
 * _strcpy - Copies a string from source to destination
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
