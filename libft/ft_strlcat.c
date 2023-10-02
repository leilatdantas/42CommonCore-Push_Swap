/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:56:01 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 21:12:05 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
LIBRARY: <string.h>
DEF: Appends the NUL-terminated string src to the end of dst. It will append at 
most size - strlen(dst) - 1 bytes, NUL-terminating the result.
RETURN VALUE: The initial length of dst plus the length of src.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	j = 0;
	while (src[j] != '\0' && i + j + 1 < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	while (src[j] != '\0')
		j++;
	return (i + j);
}
