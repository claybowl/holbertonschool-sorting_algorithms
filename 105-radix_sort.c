#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sort.h"

#define BASE 10
#define WIDTH 3

/**
 * @array: array to be sorted.
 *
 * @size: Number of elements in the array
 * 
 * Return: Array sorted by Redix (LSD) algorithm.
 */
void radix_sort(int *array, size_t size)
{
	int i, j, k, m, p, q, w = WIDTH, d = 1;
	int temp[size];

	for (i = 0; i < w; i++, d *= BASE)
	{
		for (j = 0; j < BASE; j++)
		{
			m = 0;
			for (k = 0; k < size; k++)
			{
				p = array[k] / d % BASE;
				if (p == j)
					temp[m++] = array[k];
			}
			for (k = 0; q = j; k < m; k++, q += BASE)
				array[q] = temp[k];
		}
		printf("Pass %d: ", i + 1);
		print_array(array, size);
	}
}
