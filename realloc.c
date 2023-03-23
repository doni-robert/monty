#include "monty.h"

/**
 * _memcpy - function that copies memory area
 *
 * @dest: copy destination
 * @src: copy source
 * @n: bytes to be copied
 *
 * Return: pointer to dest
 *
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	i++;
	return (dest);
}


/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size in bytes of the allocated space for ptr
 * @new_size: new size in bytes of the new memory block
 *
 * Return: the reallocated pointer or NULL if it fails
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (new_size == old_size)
		return (ptr);
	if ((new_size == 0) && (ptr != NULL))
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		free(ptr);
		return (new_ptr);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (new_size < old_size)
	{
		_memcpy(new_ptr, ptr, new_size);
		free(ptr);
		return (new_ptr);
	}

	if (new_size > old_size)
	{
		_memcpy(new_ptr, ptr, old_size);
		free(ptr);
		return (new_ptr);
	}
	return (new_ptr);
}

