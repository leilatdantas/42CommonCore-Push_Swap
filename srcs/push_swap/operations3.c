/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:32:53 by lebarbos          #+#    #+#             */
/*   Updated: 2023/10/29 17:10:08 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void ft_sa(t_stack **a, int print)
{
	t_stack *tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if(print)
		write(1, "sa\n", 4);
}

void ft_sb(t_stack **b, int print)
{
	t_stack *tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if(print)
		write(1, "sb\n", 4);
}

