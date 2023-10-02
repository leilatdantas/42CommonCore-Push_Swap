/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:07:29 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 21:15:45 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	
DEF: Allocates (with malloc) and returns a copy of s1 with the characters
specified in 'set' removed from the beginning and the end of the string.
RETURN VALUE: The trimmed string or NULL, if the allocation fails.
*/

#include "libft.h"

static int	ft_setcmp(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if ((unsigned char)set[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_setcmp(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > i && ft_setcmp(s1[j], set))
		j--;
	if (i > j)
		trimmed = ft_strdup("");
	else
		trimmed = ft_substr(s1, i, j - i + 1);
	return (trimmed);
}
