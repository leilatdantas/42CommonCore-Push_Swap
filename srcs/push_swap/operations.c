/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:32:53 by lebarbos          #+#    #+#             */
/*   Updated: 2023/10/27 16:30:57 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_sa(t_stack *a, int print)
{
	int	tmp;

	if(!a || !a->next)
		return ;
	tmp = a->nbr;
	a->nbr = a->next->nbr;
	a->next->nbr = tmp;
	if (print)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b, int print)
{
	int	tmp;

	if(!b || !b->next)
		return ;
	tmp = b->nbr;
	b->nbr = b->next->nbr;
	b->next->nbr = tmp;
	if (print)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	write(1, "ss\n", 3);
}

