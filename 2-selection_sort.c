#include "sort.h"
/**
 * selection_sort - to sort array using Selection sort algorithm
 * @array: the array to be sorted.
 * @size: the size of the array.
*/
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t min_pos, a, b;

	if (!array || !size)
		return;
	for (a = 0; a < size - 1; a++)
	{
		min_pos = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[min_pos])
			{
				min_pos = b;
			}
		}
		if (min_pos != a)
		{
			tmp = array[a];
			array[a] = array[min_pos];
			array[min_pos] = tmp;
			print_array(array, size);
		}
	}
}
