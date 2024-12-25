/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arranged.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:24:01 by drahwanj          #+#    #+#             */
/*   Updated: 2024/12/25 15:24:02 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_arranged(t_Node *list)
{
	t_Node	*curr;

	curr = list;
	while (curr != NULL && curr->next != NULL)
	{
		if (curr->data > curr->next->data)
		{
			return (0);
		}
		curr = curr->next;
	}
	return (1);
}
