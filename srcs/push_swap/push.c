/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:15:58 by lebarbos          #+#    #+#             */
/*   Updated: 2023/10/30 09:49:19 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_pa(t_stack **a, t_stack **b, int print)
{
	t_stack *tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_stackadd_front(b, tmp);
	if (print)
		write(1, "pa\n", 3);
}

void	ft_pb(t_stack **b, t_stack **a, int print)
{
	t_stack *tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_stackadd_front(a, tmp);
	if (print)
		write(1, "pb\n", 3);
}