#include "sort.h"


/**
 * Helper function for merge_sort. This merges
 * two sorted arrays (left, right) into a single (array)
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
 * Sorts array of integers in ascending order
 */
void merge_sort(int *array, size_t size) {
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
	for (size_t i = 0; i < size; i++) {
		left[i] = array[i];
	}
	for (size_t j = middle; j < size; j++) {
		right[j - middle] = array[j];
	/* merge sort left/right arrays */
	merge_sort(left, middle);
	merge_sort(right, size - middle);
	/* merge sorted left/right arrays to main array */
	merge(array, left, middle, right, size - middle);
	/* free required memory for left/right arrays */
	free(left);
	free(right);
	}
}
