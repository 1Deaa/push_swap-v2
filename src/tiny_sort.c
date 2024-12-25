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

void	sort_two(t_Node *a)
{
	if (is_arranged(a) != 1)
	{
		sa(a);
	}
}

void	sort_three(t_Node *a)
{
	int	highest_number;

	highest_number = find_highest(a);
	if (a->data == highest_number)
		ra(a);
	else if (a->next->data == highest_number)
		rra(a);
	if (a->data > a->next->data)
		sa(a);
}

void	sort_four(t_Node *a, t_Node *b)
{
	int	smallest_number;

	smallest_number = find_smallest(a);
	if (a->data == smallest_number)
		pb(a, b);
	else if (a->next->data == smallest_number)
	{
		ra(a);
		pb(a, b);
	}
	else if (a->next->next->data == smallest_number)
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

void	tiny_sort(t_Node *a, t_Node *b, int argc)
{
	if (argc == 3)
		sort_two(a);
	else if (argc == 4)
		sort_three(a);
	else if (argc == 5)
		sort_four(a, b);
}
