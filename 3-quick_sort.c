#include "sort.h"

/**
*
*
*/
void swap(int *array,int *a, int *b, size_t size)
{
	int temp = *a;

	*a = *b;
	*b = temp;
	print_array(array, size);
}


/**
*
*
*/
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int index = start;
	int i = 0;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			if (index != i)
			{
				swap(array, &array[i], &array[index], size);
			}
			index++;
		}
	}
	if (index != end)
		swap(array, &array[end], &array[index], size);
	return (index);
}

void quickSort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quickSort(array, low, pivot - 1, size);
		quickSort(array, pivot + 1, high, size);
	}
}

/**
*
*
*
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quickSort(array, 0, size - 1, size);
}
