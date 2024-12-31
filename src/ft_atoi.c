/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:33:26 by drahwanj          #+#    #+#             */
/*   Updated: 2024/12/25 15:33:26 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_atoi_error(const char *str, t_Node **list, int sign, long result)
{
	if (sign == 1 && (result > ((INT_MAX) - (*str - '0')) / 10))
		handle_error(list);
	if (sign == -1 && (result > ((-(long)INT_MIN) - (*str - '0')) / 10))
		handle_error(list);
}

int	ft_atoi(const char *str, t_Node **list)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-')
	{
		if (!((*(str + 1) >= '0') && (*(str + 1) <= '9')))
			handle_error(list);
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		ft_atoi_error(str, list, sign, result);
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		handle_error(list);
	return (sign * result);
}
