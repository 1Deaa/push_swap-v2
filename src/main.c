/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:50:33 by drahwanj          #+#    #+#             */
/*   Updated: 2024/12/25 16:19:28 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_Node	*a;
	t_Node	*b;
	int		*array;

	(void)array;
	b = NULL;
	a = NULL;
	fill_list(&a, argv, argc);
	if (is_arranged(&a) == 1 || argc < 3)
	{
		deallocate_list(&a);
		return (0);
	}
	else if (argc < 6)
	{
		tiny_sort(&a, &b, argc);
		print_list(&a);
		deallocate_list(&a);
		return (0);
	}
	array = quick_fill_sort(&a, argc);
	//big_sort
	deallocate_list(&a);
}