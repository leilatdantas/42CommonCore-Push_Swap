/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:01:19 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 16:06:23 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
LIBRARY: <ctype.h>
DEF: Checks for a digit (0 through 9)
RETURN VALUE: Nonzero if the character c falls into the tested class, and 
zero if not.
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
