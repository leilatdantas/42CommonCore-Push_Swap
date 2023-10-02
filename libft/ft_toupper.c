/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:28:39 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 21:16:03 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	
LIBRARY: <ctype.h>
DEF: Converts lowercase letters to uppercases. 
RETURN VALUE: The converted letter or c, if conversion is not possible. 
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
