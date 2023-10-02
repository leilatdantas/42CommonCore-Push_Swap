/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:43:04 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 19:36:27 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
DEF: Outputs the string ’s’ to the given file descriptor.
RETURN VALUE: None.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
