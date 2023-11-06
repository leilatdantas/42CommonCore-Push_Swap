/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:49:36 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/06 12:00:36 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	
LIBRARY: <string.h>
DEF: Returns a pointer to the first occurence of the character c in the 
string s. 
RETURN VALUE: A pointer to the matched character or NULL if the character
is not found. 
*/

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while ((unsigned char)str[i] != (unsigned char)c && str[i])
		i++;
	if ((unsigned char)c == (unsigned char)str[i])
		return ((char *)(str + i));
	return (NULL);
}
