#include "sort.h"
/**
 * merge_arrays - function to merg the sorted sub arrays
 * */
void merge_arrays(int *array, size_t lb,size_t m, size_t ub, int * cpy)
{
	size_t i = lb;
	size_t j = m + 1;
	size_t k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + lb, m - lb);
	printf("[right]: ");
	print_array(array + m, ub - m);
	k = lb;
	while (i <= m && j <= ub)
	{
		if (array[i] <= array[j])
		{
			cpy[k] = array[i];
			i++;
			k++;
		}
		else
		{
			cpy[k] = array[j];
			j++;
			k++;
		}
	}
	if (i < m)
	{
		while (j <= ub)
		{
			cpy[k] = array[j];
			j++;
			k++;
		}
	}
	else
	{
		while (i <= m)
		{
			cpy[k] = array[i];
			i++;
			k++;
		}
	}
	for (k = lb; k <= ub; k++)
	{
		array[k] = cpy[k];
	}
	printf("[Done]: ");
	print_array(cpy, ub - lb);
}
/**
 * */
void merge_recursion(int *array, size_t lb, size_t ub, int *cpy)
{
	size_t m;
	if (lb < ub)
	{
		m = (lb + ub) / 2;
		merge_recursion(cpy, lb, m, array);
		merge_recursion(cpy, m + 1, ub, array);
		merge_arrays(array, lb, m, ub, cpy);
	}
}
/**
 * */
void merge_sort(int *array, size_t size)
{
	int *cpy;
	size_t i;

	if (array == NULL || size < 2)
		return;
	cpy = malloc(size * sizeof(int));
	if (cpy == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		cpy[i] = array[i];
	}
	merge_recursion(cpy, 0, size, array);
	free(cpy);
}
