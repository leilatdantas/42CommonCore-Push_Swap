/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:20:27 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/09 14:14:41 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*get_stack_ch(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	int		j;

	i = 1;
	a = NULL;
	if (argc == 2 && !check_number(argv[1]))
		ft_checker_error(a);
	while (i < argc)
	{
		j = ft_atoi(argv[i]);
		ft_stackadd_back(&a, ft_stack_new(j));
		i++;
	}
	return (a);
}
