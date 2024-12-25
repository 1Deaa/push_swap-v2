/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:58:05 by drahwanj          #+#    #+#             */
/*   Updated: 2024/12/25 14:58:08 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_Node *a)
{
	t_Node	*first;
	t_Node	*last;

	if (a == NULL || a->next == NULL)
		return ;
	first = a;
	last = a;
	while (last->next != NULL)
		last = last->next;
	a = first->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_Node *a)
{
	t_Node	*second_last;
	t_Node	*last;

	if (a == NULL || a->next == NULL)
		return ;
	second_last = NULL;
	last = a;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = a;
	a = last;
	write(1, "rra\n", 4);
}

void	pa(t_Node *a, t_Node *b)
{
	t_Node	*temp;

	if (b == NULL)
		return ;
	temp = b;
	b = b->next;
	temp->next = a;
	a = temp;
	write(1, "pa\n", 3);
}

void	sa(t_Node *a)
{
	t_Node	*first;
	t_Node	*second;

	first = a;
	second = a->next;
	if (a == NULL || a->next == NULL)
		return ;
	first->next = second->next;
	second->next = first;
	a = second;
	write(1, "sa\n", 3);
}
