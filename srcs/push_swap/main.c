/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:22:43 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/06 14:36:22 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (!validate_stack(argc, argv))
		ft_error_print();
	a = get_stack(argc, argv);
	if (!check_repeat(a))
		ft_error_print();
	if (!check_sort(a))
		ft_sort(&a);
	ft_stackclear(&a, ft_free);
}
