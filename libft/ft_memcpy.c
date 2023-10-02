/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:18:50 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 18:00:20 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	
LIBRARY: <string.h>
DEF: Copies n bytes from memory area src to memory area dest. The memory 
area must not overlap.
RETURN VALUE: Returns a pointer to dest. 
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_aux;
	const unsigned char	*src_aux;
	size_t				i;

	i = 0;
	dest_aux = dest;
	src_aux = src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dest_aux[i] = src_aux[i];
		i++;
	}
	return (dest);
}
