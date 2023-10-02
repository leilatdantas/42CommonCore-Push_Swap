/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:54:46 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 16:05:42 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
LIBRARY: <stdlib.h>
DEF: Allocates memory for an array of nmemb elements of size bytes each. The 
allocated memory is filled with bytes of value zero.
RETURN VALUE: A pointer to the allocated memory.
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', nmemb * size);
	return (ptr);
}
