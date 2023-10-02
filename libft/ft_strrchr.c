/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:49:36 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 21:15:35 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	
LIBRARY: <string.h>
DEF: Returns a pointer to the last occurence of the character c in the string s. 
RETURN VALUE: A pointer to the matched character or NULL if the character
is not found. 
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	const char		*last;
	unsigned char	a;

	last = NULL;
	i = 0;
	a = c;
	while (s[i] != '\0')
	{
		if (s[i] == a)
			last = s + i;
		i++;
	}
	if (a == '\0')
		return ((char *)(s + i));
	return ((char *)(last));
}
