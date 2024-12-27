/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:10:01 by drahwanj          #+#    #+#             */
/*   Updated: 2024/12/25 16:17:39 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_Node **a)
{
	if (is_arranged(a) != 1)
	{
		sa(a);
	}
}

void	sort_three(t_Node **a)
{
	t_Node	*highest_node;

	highest_node = find_highest(a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	sort_four(t_Node **a, t_Node **b)
{
	t_Node	*smallest_node;

	smallest_node = find_smallest(a);
	if (*a == smallest_node)
		pb(a, b);
	else if ((*a)->next == smallest_node)
	{
		ra(a);
		pb(a, b);
	}
	else if ((*a)->next->next == smallest_node)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	else
	{
		rra(a);
		pb(a, b);
	}
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_Node **a, t_Node **b)
{
	t_Node	*smallest_node;

	smallest_node = find_smallest(a);
	if ((*a)->next == smallest_node)
		ra(a);
	else if ((*a)->next->next == smallest_node)
	{
		ra(a);
		ra(a);
	}
	else if ((*a)->next->next->next == smallest_node)
	{
		rra(a);
		rra(a);
	}
	else if ((*a)->next->next->next->next == smallest_node)
		rra(a);
	if (is_arranged(a))
		return ;
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	tiny_sort(t_Node **a, t_Node **b, int argc)
{
	if (argc == 3)
		sort_two(a);
	else if (argc == 4)
		sort_three(a);
	else if (argc == 5)
		sort_four(a, b);
	else if (argc == 6)
		sort_five(a, b);
}
