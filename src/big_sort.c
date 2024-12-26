/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:04:23 by drahwanj          #+#    #+#             */
/*   Updated: 2024/12/25 23:04:24 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int search_array(int *array, int target, int start, int end)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (target == array[i])
			return (1);
		i++;
	}
	return (0);
}

/*static int get_position(t_Node **list, int target)
{
	int		pos;
	t_Node	*loop;

	loop = *list;
	pos = 0;
	while (loop)
	{
		if (loop->data == target)
			return (pos);
		loop = loop->next;
		pos++;
	}
	return (-1);
}*/

static void call_repeat(t_Node **b, int partition_size)
{
	int	i;

	i = 0;
	while (i < partition_size / 2)
	{
		rb(b);
		i++;
	}
}

void big_sort(t_Node **a, t_Node **b, int *array, int size)
{
	int	partition_size;
	int	original_size;
	int	start;
	int	push_count;

	push_count = 0;
	start = 0;
	partition_size = size / 5;
	original_size = partition_size;
	while (push_count <= (size - (size % 5)))
	{
		if (push_count == partition_size)
		{
			partition_size += original_size;
			start += original_size;
			if (push_count != original_size)
				call_repeat(b, original_size);
		}
		if (search_array(array, (*a)->data, start, partition_size - 1))
		{
			pb(a, b);
			push_count++;
		}
		ra(a);
	}
	while (*a)
		pb(a, b);
}