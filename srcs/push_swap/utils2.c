/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:49:46 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/06 16:09:17 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

long	ft_min(t_stack *a)
{
	long	min;

	min = a->nbr;
	while (a->next)
	{
		if (a->next->nbr < min)
			min = a->next->nbr;
		a = a->next;
	}
	return (min);
}

long	ft_max(t_stack *a)
{
	long	max;

	max = a->nbr;
	while (a->next)
	{
		if (a->next->nbr > max)
			max = a->next->nbr;
		a = a->next;
	}
	return (max);
}
