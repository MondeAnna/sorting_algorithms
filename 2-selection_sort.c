#include "sort.h"

/**
 * swap_int - exchange values
 * @left: operand
 * @right: operand
 * Return: void
 */
void swap_int(int *left, int *right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

/**
 * get_min_index - index to min element
 * @array: head of array to be sorted
 * @size: size of array
 * @min: index to min value of current iterative run
 * Return: index to min element
 */
int get_min_index(int *array, size_t size, size_t min)
{
	size_t index;

	for (index = min; index < size; index++)
		if (array[index] < array[min])
			min = index;

	return (min);
}

/**
 * selection_sort - algorithm
 * @array: head of array to be sorted
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t iter, min;

	if (!array || size < 2)
		return;

	for (iter = 0; iter < size - 1; iter++)
	{
		min = get_min_index(array, size, iter);

		if (min <= iter)
			continue;

		swap_int(array + iter, array + min);
		print_array(array, size);
	}
}
