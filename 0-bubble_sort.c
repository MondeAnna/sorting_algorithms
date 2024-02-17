#include "sort.h"

/**
 * swap - exchange memory assigned values
 * @left: operand
 * @right: operand
 * Return: void
 */
void swap(int *left, int *right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

/**
 * _bubble - order of elements
 * @array: array being sorted
 * @size: size of array
 * Return: 1 if succes else 0
 */
int _bubble(int *array, size_t size)
{
	int swap_made = FALSE;
	int *left, *right;
	size_t iter = 0;

	for (iter = 0; iter < size - 1; iter++)
	{
		left = &array[iter];
		right = &array[iter + 1];

		if (*left > *right)
		{
			swap_made = TRUE;
			swap(left, right);
			print_array(array, size);
		}
	}

	return (swap_made);
}

/**
 * bubble_sort - sorting algorithm
 * @array: array being sorted
 * @size: size of array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t iter;

	if (size < 2)
		return;

	for (iter = 0; iter < size; iter++)
		if (!_bubble(array, size))
			break;
}
