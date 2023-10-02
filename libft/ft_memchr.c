/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:05:45 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 18:14:17 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
LIBRARY: <string.h>
DEF: Scans the initial n bytes of the memory area pointed to by s for the 
first instance of c. 
RETURN VALUE: A pointer to the matching byte or NULL if the character does
not occur in the given memory area. 
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
