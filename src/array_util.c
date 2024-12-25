/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:52:05 by drahwanj          #+#    #+#             */
/*   Updated: 2024/12/25 16:17:12 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

static int	partition(int array[], int low, int high)
{
	int	pivot_value;
	int	i;
	int	j;

	pivot_value = array[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
		j++;
	}
	swap(&array[i], &array[high]);
	return (i);
}

static void	quicksort_recursion(int array[], int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high);
		quicksort_recursion(array, low, pivot_index - 1);
		quicksort_recursion(array, pivot_index + 1, high);
	}
}

static void	quicksort(int array[], int length)
{
	quicksort_recursion(array, 0, length - 1);
}

int	*quick_fill_sort(t_Node **a, int argc)
{
	t_Node	*loop;
	int		i;
	int		*array;

	array = malloc(sizeof(int) * (argc - 1));
	if (array == NULL)
	{
		free(array);
		handle_error(a);
	}
	i = 0;
	loop = *a;
	while (loop != NULL)
	{
		array[i] = loop->data;
		loop = loop->next;
		i++;
	}
	quicksort(array, argc - 1);
	return (array);
}
