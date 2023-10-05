/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:54:09 by lebarbos          #+#    #+#             */
/*   Updated: 2023/10/05 19:25:12 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
// #include "../../libft.h"
#include <limits.h>

bool	check_number(char *nbr)
{
	long n;
	int i;

	n = ft_atoi(nbr);
	i = 0;
	if (n > INT_MAX || n < INT_MIN)
		return (false);
	while(nbr[i])
	{
		if (!ft_isdigit(nbr[i]) && (nbr[i] != '-' && nbr[i] != '+'))
			return (false);
		if ((nbr[i] == '-' || nbr[i] == '+') && i != 0)
			return (false);
		i++;
	}
	return(true);
}

bool	check_repeat(t_stack *a)
{
	t_stack *tmp;

	while(a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->nbr == a->nbr)
				return (false);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (true);
}

bool	validate_stack(int argc, char **argv)
{
	int	i;
	bool	result;

	i = 1;
	result = true;
	while (i < argc)
	{
		result = result && check_number(argv[i]);
		i++;
	}
	return(result);
}