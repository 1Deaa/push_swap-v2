/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:28:28 by drahwanj          #+#    #+#             */
/*   Updated: 2024/12/25 16:18:45 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Node	*find_smallest(t_Node **list)
{
	t_Node	*smallest;
	t_Node	*curr;

	if (*list == NULL)
		return (NULL);
	smallest = *list;
	curr = (*list)->next;
	while (curr != NULL)
	{
		if (curr->data < smallest->data)
			smallest = curr;
		curr = curr->next;
	}
	return (smallest);
}
