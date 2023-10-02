/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:12:22 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 17:49:56 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
LIBRARY: <string.h>
DEF: Compares the first n bytes of the memory areas s1 and s2.
RETURN VALUES: An integer less than, equal to, or greater than zero if the
first n bytes of s1 is found. 
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	i = 0;
	p1 = s1;
	p2 = s2;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
