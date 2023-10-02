/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:20:48 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 21:15:52 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	
DEF: Allocates (with malloc) and returns a substring from string 's'. The 
substring begins at index 'start' and is of maximum size 'len'.
RETURN VALUE: The substring. NULL if the allocation fails. 
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*newstring;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	newstring = malloc(sizeof(char) * (len + 1));
	if (!newstring)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newstring[i] = s[start];
		i++;
		start++;
	}
	newstring[i] = '\0';
	return (newstring);
}
