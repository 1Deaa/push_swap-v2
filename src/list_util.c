/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:41:13 by drahwanj          #+#    #+#             */
/*   Updated: 2024/12/25 15:41:14 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_end(t_Node **list, int value)
{
	t_Node	*newnode;
	t_Node	*curr;

	newnode = malloc(sizeof(t_Node));
	if (newnode == NULL)
		handle_error(*list);
	newnode->data = value;
	newnode->next = NULL;
	if (*list == NULL)
		*list = newnode;
	else
	{
		curr = *list;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = newnode;
	}
}

void	fill_list(t_Node **list, char **argv, int argc)
{
	int			i;

	i = 1;
	while (i < argc)
	{
		insert_end(list, ft_atoi(argv[i], *list));
		i++;
	}
}

void	print_list(t_Node *list)
{
	t_Node	*curr;

	curr = list;
	while (curr != NULL)
	{
		ft_printf("Data %d\n", curr->data);
		curr = curr->next;
	}
}

void	deallocate_list(t_Node **list)
{
	t_Node	*curr;
	t_Node	*temp;

	curr = *list;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*list = NULL;
}
