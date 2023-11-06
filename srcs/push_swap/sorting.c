/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:04:39 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/06 16:21:02 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_move_to_b(t_stack **a, t_stack **b)
{
	int		remaining;
	long	min;
	long	max;
	int		target;
	int		pb_needed;

	remaining = ft_stack_size(*a);
	while (remaining > 3)
	{
		min = ft_min(*a);
		max = ft_max(*a);
		target = min + ((max - min) / 2);
		pb_needed = check_bellow_target(*a, target);
		while (remaining > 3 && (pb_needed > 0))
		{
			if ((*a)->nbr < target)
			{
				ft_pb(a, b, 1);
				remaining--;
				pb_needed--;
			}
			else
				ft_ra(a, 1);
		}
	}
}

void	ft_move_to_a(t_stack **src, t_stack **dst)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*src);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(src, dst, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		rev_rotate_both(src, dst, cheapest);
	pre_push(src, cheapest, 'b');
	pre_push(dst, cheapest->target, 'a');
	ft_pa(dst, src, 1);
}

void	init_stack_b(t_stack *b, t_stack *a)
{
	set_index(a);
	set_index(b);
	set_target(b, a);
	calculate_cost(b, a);
	set_min_cost(b);
}
