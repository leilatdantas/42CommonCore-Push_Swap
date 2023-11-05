/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletedfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:27:58 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/05 20:28:45 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	set_target_a(t_stack *a, t_stack *b)
// {
// 	long best_target;
// 	t_stack	*current_b;

// 	while (a)
// 	{
// 		best_target = LONG_MIN;
// 		current_b = b;
// 		// a->target = current_b;
// 		while (current_b)
// 		{
// 			if (current_b->nbr < a->nbr && current_b->nbr > best_target)
// 			{
// 				a->target = current_b;
// 				best_target = current_b->nbr;
// 			}
// 			current_b = current_b->next;
// 		}
// 		if (best_target == LONG_MIN)
// 		{
// 			best_target = ft_max(b);
// 			a->target = ft_find_node(b, best_target);
// 		}
// 		a = a->next;
// 	}
// }

// void	calculate_cost(t_stack *src, t_stack *dst)
// {
// 	int	size_a;
// 	int	size_b;

// 	size_a = ft_stack_size(src);
// 	size_b = ft_stack_size(dst);
// 	while (src)
// 	{
// 		src->cost = src->index;
// 		if (!src->above_median)
// 			src->cost = size_a - src->index;
// 		if (src->target->above_median)
// 		{
// 			if (!src->above_median)
// 				src->cost += src->target->index;
// 			if (src->cost < src->target->index)
// 				src->cost = src->target->index;
// 		}
// 		else
// 		{
// 			if (src->above_median)
// 				src->cost += size_b - src->target->index;
// 			else
// 			{
// 				if (src->cost < (size_b - src->target->index))
// 					src->cost = size_b - src->target->index;
// 			}
// 		}
// 		src = src->next;
// 	}
// }

// void	calculate_cost(t_stack *a, t_stack *b)
// {
// 	int	size_a;
// 	int	size_b;

// 	size_a = ft_stack_size(a);
// 	size_b = ft_stack_size(b);
// 	while (a)
// 	{
// 		a->cost = a->index;
// 		if (!a->above_median)
// 			a->cost = size_a - a->index;
// 		if (!a->target->above_median)
// 			a->cost += size_b - a->target->index;
// 		else
// 			a->cost += a->target->index;
// 		a = a->next;
// 	}
// }

// void	ft_move_to_b(t_stack **src, t_stack **dst)
// {
// 	t_stack	*cheapest;
	
// 	cheapest = find_cheapest(*src);
// 	if (cheapest->above_median && cheapest->target->above_median)
// 		rotate_both(src, dst, cheapest);
// 	else if (!cheapest->above_median && !cheapest->target->above_median)
// 		rev_rotate_both(src, dst, cheapest);
// 	pre_push(src, cheapest, 'a');
// 	pre_push(dst, cheapest->target, 'b');
// 	ft_pb(src, dst, 1);
// }