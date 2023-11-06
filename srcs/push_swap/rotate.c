/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:34:32 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/06 16:11:38 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_ra(t_stack **a, int print)
{
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = ft_stack_last(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b, int print)
{
	t_stack	*tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	*b = ft_stack_last(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (print)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b, int print)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	if (print)
		write(1, "rr\n", 3);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && (*b) != cheapest->target)
		ft_rr(a, b, 1);
	set_index(*a);
	set_index(*b);
}
