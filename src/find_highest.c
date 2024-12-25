/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_highest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:27:11 by drahwanj          #+#    #+#             */
/*   Updated: 2024/12/25 16:15:58 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Node	*find_highest(t_Node **list)
{
	t_Node	*highest;
	t_Node	*curr;

	if (*list == NULL)
		return (NULL);
	highest = *list;
	curr = (*list)->next;
	while (curr != NULL)
	{
		if (curr->data > highest->data)
			highest = curr;
		curr = curr->next;
	}
	return (highest);
}
