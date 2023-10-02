/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:47:20 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/02 12:55:52 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	
LIBRARY: <string.h>
DEF: Calculates the string pointed to by str, excluding terminating null byte.
RETURN VALUE: The number of bytes in the string pointed to by s.
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
