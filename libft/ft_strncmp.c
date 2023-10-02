/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:58:00 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 21:14:55 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
LIBRARY: <string.h>
DEF: Compares the first n bytes of s1 an s2.
RETURN VALUE: An integer less than, equal to, or greater than zero if s1 
is found. 
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (i == n)
		return (0);
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
