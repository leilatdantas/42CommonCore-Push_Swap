/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:23:08 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 21:14:42 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	
LIBRARY: <string.h>
DEF: Copies up to size - 1 characters from the NUL-terminated string src to 
dst, NUL-terminating the result.
RETURN VALUE: The length of src. 
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	cpylen;

	i = 0;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	cpylen = size - 1;
	if (srclen < cpylen)
		cpylen = srclen;
	while (i < cpylen)
	{
		dst[i] = src[i];
		i++;
	}
	dst[cpylen] = '\0';
	return (srclen);
}
