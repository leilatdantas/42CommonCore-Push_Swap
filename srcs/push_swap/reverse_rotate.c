/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:45:35 by lebarbos          #+#    #+#             */
/*   Updated: 2023/10/29 19:45:02 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_rra(t_stack **a, int print)
{
	t_stack *tmp;
	t_stack *penult;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = ft_stack_last(*a);
	(*a)->next = tmp;
	while(tmp != *a)
	{
		penult = tmp;
		tmp = tmp->next;
	}
	penult->next = NULL;
	if (print)
		write(1, "rra\n", 4);
}