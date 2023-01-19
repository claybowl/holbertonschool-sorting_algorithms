#include "sort.h"


/**
 * merge - merges arrays
 *
 * @leftArray: left array
 * @leftSize: size of left array
 * @rightArray: right array
 * @rightSize: size of right array
 * Return: void
 */

void merge(int *array, int *left, int left_size, int *right, int
right_size) {
	/* defining integers */
	int i = 0, j = 0, k = 0;
	/* Compares elements and adds smallest to array */
	while (i < left_size && j < right_size) {
		if (left[i] <= right[j]) {
			array[k++] = left[j++];
		} else {
			array[k++] = right[j++];
		}
	}
	/* appends the remaining elements(left) to the result array */
	while (i < left_size) {
		array[k++] = left[i++];
	}
	/* appends the remaining elements(right) to the result array */
	while (j < right_size) {
		array[k++] = right[j++];
	}
}

/**
 * merge_sort - merge sort recursively
 *
 * @array: int array to sort
 * @size: size of array
 * Return: void
 */

void merge_sort(int *array, int size) {
	/* Return if array is smaller than 2 elements */
	if (size < 2) {
		return;
	}
	/* define middle index of array */
	int middle = size / 2;
	/* Allocating memery for left/right arrays */
	int *left = (int*)malloc(middle * sizeof(int));
	int *right = (int*)malloc((size - middle) * sizeof(int));
	/* Move elements from the original array to the left/right (sub)arrays */
	int i = 0, j = middle;
    while (i < middle) {
        left[i] = array[i];
        i++;
    }
    while (j < size) {
        right[j - middle] = array[j];
        j++;
    }
	/* merge sort left/right arrays */
	merge_sort(left, middle);
	merge_sort(right, size - middle);
	/* merge sorted left/right arrays to main array */
	merge(array, left, middle, right, size - middle);
	/* free required memory for left/right arrays */
	free(left);
	free(right);
}
