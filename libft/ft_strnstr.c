/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:27:44 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 21:15:22 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: <string.h>
DEF: Locates the first occurence of the null-terminated string little in the 
string big, where not more than len characters are sarched.
RETURN VALUE: If little is an empty string, big is returned; if little occurs
nowhere in big, NULL is returned; otherwise a pointer to the firstcharacter of 
the first occurence of little is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *) big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((i + j) < len && big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
