#include "sort.h"
/**
 * swap_int - to swap to integer values
 * @x: first int to swap
 * @y: second int to swap with
 * Return: void function return nothing
 */
void swap_int(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
/**
 * Lomuto_part - function to partition the desired array
 * @array: the input array we want to partition it
 * @size: the array size
 * @start: int low bondery
 * @end: int high boundary
 * Return: pivot index
*/
int Lomuto_part(int *array, size_t size, int start, int end)
{
	int pv_value, i, j;

	pv_value = array[end];
	i = start - 1;

	for (j = start; j < end; j++)
	{
		if (array[j] < pv_value)
		{
			i++;
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[end] < array[i + 1])
	{
		swap_int(&array[i + 1], &array[end]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quick_recursion - to apply the recursive divide partion an the array
 * @array: input array to be sorted
 * @size: array length
 * @start: int low bondery
 * @end: int high boundary
 * Return: void function return nothing
 */
void quick_recursion(int *array, size_t size, int start, int end)
{
	int pv_index;

	if (start < end)
	{
		pv_index = Lomuto_part(array, size, start, end);
		quick_recursion(array, size, start, pv_index - 1);
		quick_recursion(array, size, pv_index + 1, end);
	}
}
/**
 * quick_sort - to sort array using the Quick sort algorithm
 * @array: int array to be sorted
 * @size: is the lenght of the input array
 * Return: void function return nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_recursion(array, size, 0, size - 1);
}
