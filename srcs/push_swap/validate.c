/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:54:09 by lebarbos          #+#    #+#             */
/*   Updated: 2023/10/04 15:56:15 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
// #include "../../libft.h"
#include <limits.h>

bool	check_number(char *nbr)
{
	long n;

	n = ft_atoi2(nbr);
	if (n > INT_MAX || n < INT_MIN)
		return (false);
	while(*nbr)
	{
		if (ft_isalpha(*nbr))
			return (false);
		else if ((!ft_isalnum(*nbr)) && (*nbr != '-' && *nbr != '+'))
			return (false);
		nbr++;
	}
	return(true);
}

// bool	check_repeat(t_stack *a)
// {
// 	t_stack *tmp;
// 	bool result;

// 	result = true;
// 	while(a->next)
// 	{
// 		tmp = a;
// 		while (tmp->next)
// 		{
// 			tmp = tmp->next;
// 			if (tmp->nbr == a->nbr)
// 			{
// 				ft_stackclear(&tmp, ft_free);
// 				return (false);
// 			}
// 		}
// 		a = a->next;
// 	}
// 	return (true);
// }

long *get_nbrs(t_stack *a)
{
	long *nbrs;
	int i;

	i = 0;
	nbrs = (long *)malloc(sizeof(long) * ft_stack_size(a));
	while(i < ft_stack_size(a))
	{
		nbrs[i] = a->nbr;
		a = a->next;
		i++;
	}
	return(nbrs);
}


bool	check_repeat(t_stack *a)
{
	int i;
	int j;
	long *nbrs;

	i = 0;
	j = 0;
	nbrs = get_nbrs(a);
	while(nbrs[i])
	{
		j = i + 1;
		while (nbrs[j])
		{
			if (nbrs[i] == nbrs[j])
				return(false);
			j++;
		}
		i++;
	}
	free(nbrs);
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