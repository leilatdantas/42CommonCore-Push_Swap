/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:07:41 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/06 16:24:19 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	calculate_cost(t_stack *src, t_stack *dst)
{
	int	size_src;
	int	size_dst;

	size_src = ft_stack_size(src);
	size_dst = ft_stack_size(dst);
	while (src)
	{
		update_cost(src, size_src, size_dst);
		src = src->next;
	}
}

void	set_min_cost(t_stack *stack)
{
	t_stack	*cheapest;
	long	cheapest_value;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest = stack;
		}
		else
			stack->min_cost = false;
		stack = stack->next;
	}
	cheapest->min_cost = true;
}

t_stack	*find_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->min_cost)
			return (stack);
		else
			stack->min_cost = false;
		stack = stack->next;
	}
	return (NULL);
}

void	update_cost(t_stack *src, int size_src, int size_dst)
{
	src->cost = src->index;
	if (!src->above_median)
		src->cost = size_src - src->index;
	if (src->target->above_median)
	{
		if (!src->above_median)
			src->cost = src->target->index + size_src - src->index;
		else if (src->cost < src->target->index)
			src->cost = src->target->index;
	}
	else
	{
		if (src->above_median)
			src->cost += size_dst - src->target->index;
		else if (src->cost < (size_dst - src->target->index))
			src->cost = size_dst - src->target->index;
	}
}
