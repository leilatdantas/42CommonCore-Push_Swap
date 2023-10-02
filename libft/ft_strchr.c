/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:49:36 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 20:24:25 by lebarbos         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	a;

	a = c;
	i = 0;
	while (s[i] != a && s[i])
		i++;
	if (a == s[i])
		return ((char *)(s + i));
	return (NULL);
}
