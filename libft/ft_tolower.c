/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:44:59 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 21:15:57 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: <ctype.c>
DEF: Converts uppercase letters to lowercase.
RETURN VALUE: The converted letter, or c if the conversion was not possible.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
