#include "sort.h"
/**
 * bubble_sort - function to array of in ascending order using the Bubble sort
 * @array: the input arry to be printed
 * @size: size of the input array
 * Return: void function returns nothing
*/
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t a, b;

	if (!array || size < 2)
		return;
	for (a = 0; a < size - 1; a++)
	{
		for (b = 0; b < size - 1 - a; b++)
		{
			if (array[b] > array[b + 1])
			{
				tmp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
