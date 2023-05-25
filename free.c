#include "main.h"

/**
 * free_array - frees an array and its components
 * @array: description
 * @size: description
 */

void free_array(char **array, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
		free(array[i]);
	free(array);
}

/**
 * free_null_terminated_array - frees an array and its components
 * @array: description
 */

void free_null_terminated_array(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
}

/**
 * free_env - free environment
 * Return: description
 */

void free_env(void)
{
	int index;

	for (index = 0; environ[index]; index++)
		free(environ[index]);
	free(environ);
}
