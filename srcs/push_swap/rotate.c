/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:34:32 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/05 20:50:19 by lebarbos         ###   ########.fr       */
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
