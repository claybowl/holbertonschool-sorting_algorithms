#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sort.h"

#define BASE 10
#define WIDTH 3

/**
 * radix_sort - sorts array of int in ascending order using Radix sort
 * @array: array to be sorted.
 * @size: Number of elements in the array
 *
 * Return: void.
 */
void radix_sort(int *array, size_t size)
{
	/* Defines variables for loops */
	size_t i, j, k, p, w = WIDTH, d = 1;
	/* Create our temporary array */
	int *temp = NULL;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	/* Loops through digit places. Starts with least significant (right) */
	for (i = 0; i < w; i++, d *= BASE)
	{
		int count[BASE] = {0};

		for (j = 0; j < size; j++)
			count[(array[j] / d) % BASE]++;

		for (j = 1; j < BASE; j++)
			count[j] += count[j - 1];

		for (j = size - 1; (int)j >= 0; j--)
		{
			p = (array[j] / d) % BASE;
			temp[count[p] - 1] = array[j];
			count[p]--;
		}

		for (k = 0; k < size; k++)
			array[k] = temp[k];

		print_array(array, size);
	}

	free(temp);
}
