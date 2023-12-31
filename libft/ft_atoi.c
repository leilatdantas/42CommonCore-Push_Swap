/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:39:30 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/06 14:14:46 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	
LIBRARY: <stdlib.h>
DEF: Converts the inicial portion of the string pointed to by nptr to int.
RETURN VALUE: The converted value. 
*/

#include "libft.h" 

long	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = sign * (-1);
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return (result * sign);
}
