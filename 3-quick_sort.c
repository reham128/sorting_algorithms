#include "sort.h"
/**
 * swap_int - to swap to integer values
 * @array: array to be printed
 * @size: the array length
 * @x: first int to swap
 * @y: second int to swap with
 * Return: void function return nothing
 */
void swap_int(int *array, size_t size, int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
	print_array((const int *)array, size);
}
/**
 * Lomuto_part - function to partition the desired array
 * @array: the input array we want to partition it
 * @start: int low bondery
 * @end: int high boundary
 * Return: pivot index
*/
int Lomuto_part(int *array, size_t size, int start, int end)
{
	int pv_value, i, j;

	pv_value = array[end];
	i = start;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pv_value)
		{
			swap_int(array, size, &array[i], &array[j]);
			i++;
		}
	}
	swap_int(array, size, &array[i], &array[end]);
	return (i);
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
