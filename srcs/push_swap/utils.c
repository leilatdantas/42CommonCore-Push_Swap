/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:45:32 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/07 09:31:13 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack	*get_stack(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	int		j;

	i = 1;
	a = NULL;
	if (argc == 2)
		exit(EXIT_SUCCESS);
	while (i < argc)
	{
		j = ft_atoi(argv[i]);
		ft_stackadd_back(&a, ft_stack_new(j));
		i++;
	}
	return (a);
}

long	ft_min(t_stack *a)
{
	long	min;

	min = a->nbr;
	while (a->next)
	{
		if (a->next->nbr < min)
			min = a->next->nbr;
		a = a->next;
	}
	return (min);
}

long	ft_max(t_stack *a)
{
	long	max;

	max = a->nbr;
	while (a->next)
	{
		if (a->next->nbr > max)
			max = a->next->nbr;
		a = a->next;
	}
	return (max);
}

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
