/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:16:27 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/10 11:48:22 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_free(void *x)
{
	if (!x)
		return ;
	free(x);
}

void	ft_error_print(t_stack *a)
{
	write(2, "Error\n", 6);
	ft_stackclear(&a, ft_free);
	exit(EXIT_FAILURE);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
