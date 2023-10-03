/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:45:32 by lebarbos          #+#    #+#             */
/*   Updated: 2023/10/03 15:55:17 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(long content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr= content;
	new->next = NULL;
	return (new);
}

t_stack	*ft_stack_last(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new || !stack)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = ft_stack_last(*stack);
	last->next = new;
}

int	ft_stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

long	ft_atoi2(char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return (result * sign);
}

// void	ft_stackdelone(t_stack *stack, void (*del)(long x))
// {
// 	if (!stack || !del)
// 		return ;
// 	del(stack->nbr);
// 	free(stack);
// }

// void	ft_stackclear(t_stack **stack, void (*del)(void*))
// {
// 	t_stack	*aux;

// 	if (!*stack || !del)
// 		return ;
// 	while (*stack)
// 	{
// 		aux = (*stack)->next;
// 		ft_stackdelone(*stack, del);
// 		*stack = aux;
// 	}
// }

void	test_print(t_stack *a)
{
	t_stack *tmp;
	
	tmp = a;
	while(tmp)
	{
		printf("%ld ", tmp->nbr);
		tmp = tmp->next;
	}
}
