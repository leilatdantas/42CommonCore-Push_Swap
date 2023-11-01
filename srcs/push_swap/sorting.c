/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:03:29 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/01 12:53:46 by lebarbos         ###   ########.fr       */
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
	if ((*a)->nbr == ft_max(*a))
		ft_ra(a, 1);
	else if ((*a)->next->nbr == ft_max(*a))
		ft_rra(a, 1);
	if ((*a)->nbr > (*a)->next->nbr)
		ft_sa(a, 1);
}

void	set_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	median = ft_stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i < median)
			stack->above_median = true;
		else
			stack->above_median = false;
		i++;
		stack = stack->next;
	}
}

void	set_target(t_stack *a, t_stack *b)
{
	long best_target;
	
	while (a)
	{
		
	}
}

void	init_stack(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target(a, b);
	calculate_cost(a, b);
	set_min_cost(a);
}

void	ft_big_sort(t_stack **a)
{
	t_stack *b;

	b = NULL;
	ft_pb(&b, a, 1);
	ft_pb(&b, a, 1);
	init_stack(*a, b);
	
}

void	ft_sort(t_stack **a)
{
	printf("tamanho da stack: %d\nmenor valor da stack: %lu\n", ft_stack_size(*a), ft_min(*a));
	if (ft_stack_size(*a) == 2)
		ft_sa(a, 1);
	if (ft_stack_size(*a) == 3)
		ft_sort_three(a);
	else 
		ft_big_sort(*a);
}