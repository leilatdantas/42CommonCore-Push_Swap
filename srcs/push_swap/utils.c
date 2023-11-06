/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:45:32 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/06 15:15:05 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_mod(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if ((*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error_print();
		result = result * 10 + (*str - 48);
		str++;
	}
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		ft_error_print();
	return (result * sign);
}

void	ft_free_array(char	**array)
{
	char	*tmp;

	if (!array)
		return ;
	while (*array)
	{
		tmp = *array;
		array++;
		free(tmp);
	}
	*array = NULL;
}

t_stack *process_quote(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi(tmp[i]);
		ft_stackadd_back(&a, ft_stack_new(j));
		i++;
	}
	ft_free_array(tmp);
	ft_free(tmp);
	return(a);
}

t_stack	*get_stack(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc == 2)
		a = process_quote(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi_mod(argv[i]);
			ft_stackadd_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}

bool	check_sort(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->nbr < a->nbr)
				return (false);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (true);
}

t_stack	*ft_stack_new(long content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = content;
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

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (!new || !stack)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
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

void	ft_free(void *x)
{
	if (!x)
		return ;
	free(x);
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

void	test_print(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		printf ("%ld ", tmp->nbr);
		tmp = tmp->next;
	}
}
