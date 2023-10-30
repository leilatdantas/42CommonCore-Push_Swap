/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:03:29 by lebarbos          #+#    #+#             */
/*   Updated: 2023/10/30 12:38:49 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

long	ft_min(t_stack *a)
{
	long min;

	min = a->nbr;
	while(a->next)
	{
		if(a->next->nbr < min)
			min = a->next->nbr;
		a = a->next;
	}
	return (min);
}
long	ft_max(t_stack *a)
{
	long max;

	max = a->nbr;
	while(a->next)
	{
		if(a->next->nbr > max)
			max = a->next->nbr;
		a = a->next;
	}
	return (max);
}

void	ft_sort_three(t_stack **a)
{
	if (ft_max(*a) == (*a)->nbr)
	{
		ft_ra(a, 1);
		if (!check_sort(*a))
			ft_sa(a, 1);
	}
	else if (ft_min(*a) == (*a)->nbr || ft_min(*a) == (*a)->next->nbr)
	{
		ft_sa(a, 1);
		if (!check_sort(*a))
			ft_ra(a, 1);
	}
	else
		ft_rra(a, 1);
}

void	ft_sort(t_stack **a)
{
	printf("tamanho da stack: %d\nmenor valor da stack: %lu\n", ft_stack_size(*a), ft_min(*a));
	if (ft_stack_size(*a) == 2)
		ft_sa(a, 1);
	if (ft_stack_size(*a) == 3)
	{
		ft_sort_three(a);
	}
	// test_print(*a);
}