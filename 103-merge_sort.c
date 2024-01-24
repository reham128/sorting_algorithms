#include "sort.h"
/**
 * merge_arrays - function to merg the sorted sub arrays
 * @array: is the input array to be sorted
 * @lb: is the lowe band of subarray
 * @m: is the middel index of the array
 * @ub: is the uber band of subarray
 * @cpy: is the array copy
 * Return: void function returns nothing
 */
void merge_arrays(int *array, size_t lb, size_t m, size_t ub, int *cpy)
{
	size_t i = lb;
	size_t j = m;
	size_t k = lb;

	printf("Merging...\n[left]: ");
	print_array(array + lb, m - lb);
	printf("[right]: ");
	print_array(array + m, ub - m);
	while (k < ub)
	{
		if (i < m && (j >= ub || array[i] <= array[j]))
		{
			cpy[k] = array[i++];
		}
		else
		{
			cpy[k] = array[j++];
		}
		k++;
	}
	printf("[Done]: ");
	print_array(cpy + lb, ub - lb);
}
/**
 * merge_recursion - function to recrusive divide the array
 * @array: is the input array to be sorted
 * @lb: is the lowe band of subarray
 * @ub: is the uber band of subarray
 * @cpy: is the array copy
 * Return: void function returns nothing
*/
void merge_recursion(int *array, size_t lb, size_t ub, int *cpy)
{
	size_t m;

	if (ub - lb < 2)
	{
		return;
	}
	if (lb < ub)
	{
		m = (lb + ub) / 2;
		merge_recursion(cpy, lb, m, array);
		merge_recursion(cpy, m, ub, array);
		merge_arrays(array, lb, m, ub, cpy);
	}
}
/**
 * merge_sort - function to sort an array using merge algorithm
 * @array: is the input array to be sorted
 * @size: is the array size
 * Return: void function returns nothing
*/
void merge_sort(int *array, size_t size)
{
	int *cpy;
	size_t i;

	if (array == NULL || size < 2)
	{
		return;
	}
	cpy = malloc(size * sizeof(int));
	if (cpy == NULL)
	{
		free(cpy);
		return;
	}
	for (i = 0; i < size; i++)
	{
		cpy[i] = array[i];
	}
	merge_recursion(cpy, 0, size, array);
	free(cpy);
}
