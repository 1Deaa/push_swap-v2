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

static int	search_array(int *array, int target, int start, int end)
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

static void	divide(t_Node **b, int partition_size)
{
	int	i;

	i = 0;
	while (i < partition_size / 2)
	{
		rb(b);
		i++;
	}
}

void	process_b(t_Node **a, t_Node **b, int *array, t_partition_info *info)
{
	while (info->push_count <= info->array_size)
	{
		if (info->push_count == info->part_size)
		{
			info->part_size += info->original_size;
			info->start += info->original_size;
			if (info->push_count != info->original_size)
				divide(b, info->original_size);
		}
		if (search_array(array, (*a)->data, info->start, info->part_size - 1))
		{
			pb(a, b);
			info->push_count++;
		}
		ra(a);
	}
	while (*a)
		pb(a, b);
}

void	big_sort(t_Node **a, t_Node **b, int *array, int size)
{
	t_partition_info	info;

	info.push_count = 0;
	info.start = 0;
	info.original_size = size / 5;
	info.part_size = info.original_size;
	info.array_size = size - (size % 5);
	process_b(a, b, array, &info);
}
