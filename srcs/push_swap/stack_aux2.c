/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_aux2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:53:48 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/06 16:21:22 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_stackclear(t_stack **stack, void (*del)(void*))
{
	t_stack	*aux;

	if (!*stack || !del)
		return ;
	while (*stack)
	{
		aux = (*stack)->next;
		ft_free(*stack);
		*stack = aux;
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
