/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:44:19 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 18:24:50 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	LIBRARY: <string.h>
**	DEF: Copies n bytes from memory area src to memory area dst. The memory 
**	areas may overlap. 
**	RETURN VALUE: A pointer to dest. 
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_aux;
	const unsigned char	*src_aux;

	dest_aux = dest;
	src_aux = src;
	if (!dest && !src)
		return (NULL);
	if (dest_aux == src_aux)
		return (dest);
	if (dest_aux > src_aux)
	{
		src_aux = src_aux + n - 1;
		dest_aux = dest_aux + n - 1;
		while (n--)
			*dest_aux-- = *src_aux--;
	}
	else
	{
		while (n--)
			*dest_aux++ = *src_aux++;
	}
	return (dest);
}
