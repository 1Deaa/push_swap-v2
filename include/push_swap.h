/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:51:42 by drahwanj          #+#    #+#             */
/*   Updated: 2024/12/25 14:51:43 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_Node;

void	ra(t_Node *a);
void	rra(t_Node *a);
void	pa(t_Node *a, t_Node *b);
void	sa(t_Node *a);
void	rb(t_Node *b);
void	rrb(t_Node *b);
void	pb(t_Node *a, t_Node *b);
void	sb(t_Node *b);
void	tiny_sort(t_Node *a, t_Node *b, int argc);
void	handle_error(t_Node *list);
void	deallocate_list(t_Node **list);
void	fill_list(t_Node **list, char **argv, int argc);
void	print_list(t_Node *list);
int		is_arranged(t_Node *list);
int		find_highest(t_Node *list);
int		find_smallest(t_Node *list);
int		ft_atoi(const char *str, t_Node *list);
int		*quick_fill_sort(t_Node **a, int argc);

#endif