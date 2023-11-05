/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:03:29 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/05 13:48:16 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

long	ft_min(t_stack *a)
{
	long min;

	min = a->nbr;
	// if (!a)
	// 	return (0);
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

t_stack	*ft_find_node(t_stack *stack, long nbr)
{
	while (stack)
	{
		if (stack->nbr == nbr)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	set_target_a(t_stack *a, t_stack *b)
{
	long best_target;
	t_stack	*current_b;

	while (a)
	{
		best_target = LONG_MIN;
		current_b = b;
		// a->target = current_b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_target)
			{
				a->target = current_b;
				best_target = current_b->nbr;
			}
			current_b = current_b->next;
		}
		if (best_target == LONG_MIN)
		{
			best_target = ft_max(b);
			a->target = ft_find_node(b, best_target);
		}
		a = a->next;
	}
}


void	set_target_b(t_stack *b, t_stack *a)
{
	long	best_target;
	t_stack	*current_a;

	while (b)
	{
		best_target = LONG_MAX;
		current_a = a;
		b->target = current_a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_target)
			{
				b->target = current_a;
				best_target = current_a->nbr;
			}
			current_a = current_a->next;
		}
		if (best_target == LONG_MAX)
		{
			best_target = ft_min(a);
			b->target = ft_find_node(a, best_target);
		}
		b = b->next;
	}
}

void	calculate_cost(t_stack *src, t_stack *dst)
{
	int	size_a;
	int	size_b;

	size_a = ft_stack_size(src);
	size_b = ft_stack_size(dst);
	while (src)
	{
		src->cost = src->index;
		if (!src->above_median)
			src->cost = size_a - src->index;
		if (src->target->above_median)
		{
			if (!src->above_median)
				src->cost += src->target->index;
			if (src->cost < src->target->index)
				src->cost = src->target->index;
		}
		else
		{
			if (src->above_median)
				src->cost += size_b - src->target->index;
			else
			{
				if (src->cost < (size_b - src->target->index))
					src->cost = size_b - src->target->index;
			}
		}
		src = src->next;
	}
}

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



void	set_min_cost(t_stack *a)
{
	t_stack	*cheapest;
	long	cheapest_value;

	if (!a)
		return ;
	cheapest_value = LONG_MAX;
	while (a)
	{
		if(a->cost < cheapest_value)
		{
			cheapest_value = a->cost;
			cheapest = a;
		}
		a = a->next;
	}
	cheapest->min_cost = true;
}

void	init_stack(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	calculate_cost(a, b);
	set_min_cost(a);
}


t_stack *find_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->min_cost)
			return(stack);
		stack = stack->next;
	}
	return (NULL);
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

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && (*b) != cheapest->target)
		ft_rr(a, b, 1);
	set_index(*a);
	set_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && (*b) != cheapest->target)
		ft_rrr(a, b, 1);
	set_index(*a);
	set_index(*b);
}

void	ft_move_to_b(t_stack **src, t_stack **dst)
{
	t_stack	*cheapest;
	
	cheapest = find_cheapest(*src);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(src, dst, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		rev_rotate_both(src, dst, cheapest);
	pre_push(src, cheapest, 'a');
	pre_push(dst, cheapest->target, 'b');
	ft_pb(src, dst, 1);
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
	ft_pa(src, dst, 1);
}

void	init_stack_b(t_stack *b, t_stack *a)
{
	set_index(a);
	set_index(b);
	set_target_b(b, a);
	calculate_cost(b, a);
	set_min_cost(b);
}

void	findMinMax(t_stack *stack, int *min, int *max)
{
	*min = ft_min(stack);
	*max = ft_max(stack);
}

void	move_smallest(t_stack **a, t_stack **b)
{
    int remaining = ft_stack_size(*a);
    int groupSize = remaining/2; // Tamanho inicial do grupo
    int min, max;

    while (remaining > 3) {
        findMinMax(*a, &min, &max);
        int target = min + ((max - min) / 2); // Cálculo do valor alvo inicial

        while (remaining > 3) 
		{
            int moved = 0;
            int targetUpdated = 0; // Flag para controlar a atualização do valor alvo
			int iterations = 0;
            while (moved < groupSize && iterations < remaining && remaining > 3)
			{
                if ((*a)->nbr < target) 
				{
                    ft_pb(a, b, 1);
                    moved++;
                    remaining--;
                } else {
                    ft_ra(a, 1);
                }
				iterations++;
            }

            findMinMax(*a, &min, &max); // Atualização dos valores mínimo e máximo
            // Verificar se há números abaixo do target para atualização do target
            if (*a != NULL && (*a)->nbr >= target) 
			{
                target = min + (max - min) / 2;
                targetUpdated = 1;
            }

            // Atualizar o valor alvo sem modificar o tamanho do grupo
            if (!targetUpdated && (*a) != NULL && (*a)->nbr < target) {
                target = min + (max - min) / 2;
            }
        }
    }
}

void	ft_big_sort(t_stack **a)
{
	t_stack	*b;
	int		size_a;

	size_a = ft_stack_size(*a);
	b = NULL;
	if (size_a-- > 3 && !check_sort(*a))
		ft_pb(a, &b, 1);
	if (size_a-- > 3 && !check_sort(*a))
		ft_pb(a, &b, 1);
	if (size_a > 3 && !check_sort(*a))
	{
		move_smallest(a, &b);
		// init_stack(*a, b);
		// ft_move_to_b(a, &b);
	}
	ft_sort_three(a);
	// if (!check_sort(*a))
	// 	ft_sa(a, 1);
	while(b)
	{
		init_stack_b(b, *a);
		ft_move_to_a(&b, a);
	}
	set_index(*a);
	ft_stackclear(&b, ft_free);
}

void	ft_sort(t_stack **a)
{
	t_stack *min;

	min = NULL;
	if (ft_stack_size(*a) == 2)
		ft_sa(a, 1);
	else if (ft_stack_size(*a) == 3)
		ft_sort_three(a);
	else 
		ft_big_sort(a);
	min = ft_find_node(*a, ft_min(*a));
	while ((*a) != min)
	{
		if (min->above_median)
			ft_ra(a, 1);
		else
			ft_rra(a, 1);
	}
}