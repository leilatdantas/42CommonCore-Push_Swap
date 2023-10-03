/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:54:09 by lebarbos          #+#    #+#             */
/*   Updated: 2023/10/03 14:43:31 by lebarbos         ###   ########.fr       */
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
		else if (!ft_isalnum(*nbr))
			return (false);
		nbr++;
	}
	return(true);
}

//  make f

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