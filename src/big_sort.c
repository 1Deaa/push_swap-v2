/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:04:23 by drahwanj          #+#    #+#             */
/*   Updated: 2024/12/27 19:41:10 by drahwanj         ###   ########.fr       */
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

void	process_a(t_Node **a, t_Node **b, int size)
{
	int	highest;
	int	position;

	highest = (find_highest(b))->data;
	position = get_position(b, highest);
	if (position < size / 2)
	{
		while (position-- > 0)
			rb(b);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			rrb(b);
	}
	pa(a, b);
}

void	process_b(t_Node **a, t_Node **b, int *array, t_partition_info *info)
{
	while ((info->array_size - info->push_count) / info->di)
	{
		if (info->push_count == info->part_size)
		{
			info->part_size += (info->array_size - info->push_count) / info->di;
			info->start += info->push_count_last;
		}
		while (search_array(array, (*a)->data,
				info->start, info->part_size - 1))
		{
			pb(a, b);
			info->push_count++;
			info->push_count_last = info->part_size - info->start;
		}
		ra(a);
	}
	while (*a)
		pb(a, b);
}

void	big_sort(t_Node **a, t_Node **b, int *array, int size)
{
	t_partition_info	info;

	info.di = 4;
	if (size >= 250)
		info.di = 7;
	info.push_count = 0;
	info.push_count_last = 0;
	info.start = 0;
	info.part_size = size / info.di;
	info.array_size = size - (size % info.di);
	process_b(a, b, array, &info);
	while (*b)
	{
		process_a(a, b, size);
		size--;
	}
}
