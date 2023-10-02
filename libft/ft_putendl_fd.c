/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:58:08 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 19:28:31 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Outputs the string ’s’ to the given file descriptor followed by a newline.
RETURN VALUE: None.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s != NULL)
	{
		ft_putstr_fd(s, fd);
	}
	ft_putchar_fd('\n', fd);
}
