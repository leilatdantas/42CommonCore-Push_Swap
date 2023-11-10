/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:00:31 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/10 11:49:15 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	check_bellow_target(t_stack *a, int target)
{
	int	result;

	result = 0;
	while (a)
	{
		if (a->nbr < target)
			result++;
		a = a->next;
	}
	return (result);
}

t_stack	*find_bellow(t_stack *a, int target)
{
	t_stack	*result;

	result = a;
	while (result->next)
	{
		if (result->nbr < target)
		{
			return (result);
		}
		result = result->next;
	}
	return (a);
}

void	pre_push(t_stack **stack, t_stack *cheapest, char k)
{
	while ((*stack) != cheapest)
	{
		if (k == 'a')
		{
			if (cheapest->above_median)
				ft_ra(stack, 1);
			else
				ft_rra(stack, 1);
		}
		else if (k == 'b')
		{
			if (cheapest->above_median)
				ft_rb(stack, 1);
			else
				ft_rrb(stack, 1);
		}
	}
}

void	set_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_target(t_stack *src, t_stack *dst)
{
	long	best_target;
	t_stack	*current_a;

	while (src)
	{
		best_target = LONG_MAX;
		current_a = dst;
		while (current_a)
		{
			if (current_a->nbr > src->nbr && current_a->nbr < best_target)
			{
				src->target = current_a;
				best_target = current_a->nbr;
			}
			current_a = current_a->next;
		}
		if (best_target == LONG_MAX)
		{
			best_target = ft_min(dst);
			src->target = ft_find_node(dst, best_target);
		}
		src = src->next;
	}
}
