/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:59:09 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 16:06:15 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
LIBRARY: <ctype.h>
DEF: Checks wheter c is a 7-bit unsigned char value that fits into the ASCII 
character set.
RETURN VALUE: Nonzero if the character c falls into the tested class, and 
zero if not. 
*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
