#include "sort.h"

/**
 * _swap_int - exchange values
 * @left: operand
 * @right: operand
 * Return: void
 */
void _swap_int(int *left, int *right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

/**
 * partition_hoare - separate values areound last element
 * @array: head of array
 * @size: size of array
 * @start: start of array
 * @end: end of array (inclusive)
 * Return: index of left boundary (pivot - 1)
 */
int partition_hoare(int *array, size_t size, int start, int end)
{
	int pivot = array[start];

	while (TRUE)
	{
		while (array[start] < pivot)
			start++;

		while (array[end] > pivot)
			end--;

		if (start >= end)
			break;

		_swap_int(array + start, array + end);
		print_array(array, size);
	}

	return (end);
}

/**
 * sort_hoare - body of algorithm
 * @array: array to be sorted
 * @size: size of array
 * @start: start of array
 * @end: end of array (inclusive)
 * Return: void
 */
void sort_hoare(int *array, size_t size, int start, int end)
{
	int boundary;

	if (start < 0 || end < 0 || start >= end)
		return;

	boundary = partition_hoare(array, size, start, end);
	sort_hoare(array, size, start, boundary);
	sort_hoare(array, size, boundary + 1, end);
}

/**
 * quick_sort_hoare - algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort_hoare(array, size, 0, size - 1);
}
