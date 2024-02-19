#include "sort.h"

/**
 * _swap - exchange values
 * @left: operand
 * @right: operand
 * Return: void
 */
void _swap(int *left, int *right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

/**
 * partition - separate values areound last element
 * @array: head of array
 * @size: size of array
 * @start: start of array
 * @end: end of array (inclusive)
 * Return: index of left boundary (pivot - 1)
 */
int partition(int *array, size_t size, int start, int end)
{
	int pivot = array[end];
	int boundary = start;

	while (start < end)
	{
		if (array[start] < pivot)
		{
			_swap(array + start, array + boundary);

			if (boundary != start)
				print_array(array, size);

			boundary++;
		}
		start++;
	}

	_swap(array + boundary, array + end);

	if (boundary != end)
		print_array(array, size);

	return (boundary);
}

/**
 * sort - body of algorithm
 * @array: array to be sorted
 * @size: size of array
 * @start: start of array
 * @end: end of array (inclusive)
 * Return: void
 */
void sort(int *array, size_t size, int start, int end)
{
	int boundary;

	if (start >= end)
		return;

	boundary = partition(array, size, start, end);
	sort(array, size, start, boundary - 1);
	sort(array, size, boundary + 1, end);
}

/**
 * quick_sort - algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, size, 0, size - 1);
}
