/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:58:17 by drahwanj          #+#    #+#             */
/*   Updated: 2024/12/25 14:58:17 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_Node **b)
{
	t_Node	*first;
	t_Node	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	*b = first->next;
	last->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	rrb(t_Node **b)
{
	t_Node	*second_last;
	t_Node	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	second_last = NULL;
	last = *b;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
}

void	pb(t_Node **a, t_Node **b)
{
	t_Node	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
}

void	sb(t_Node **b)
{
	t_Node	*first;
	t_Node	*second;

	first = *b;
	second = (*b)->next;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	first->next = second->next;
	second->next = first;
	*b = second;
	write(1, "sb\n", 3);
}
