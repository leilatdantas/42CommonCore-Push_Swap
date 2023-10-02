/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:27:46 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 21:14:34 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
DEF: Applies the function 'f' to each character of the string 's', and 
passing its index as first argument to create a new string (with malloc) 
resulting from successive applications of 'f'
RETURN VALUE: The string created from the successive applications of 'f'. 
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
