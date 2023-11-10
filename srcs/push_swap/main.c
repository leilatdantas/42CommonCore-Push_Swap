/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:22:43 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/07 13:12:29 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (!validate_stack(argc, argv))
		ft_error();
	if (argc <= 1)
		exit(1);
	a = get_stack(argc, argv);
	if (!check_repeat(a))
		ft_error_print(a);
	if (!check_sort(a))
		ft_sort(&a);
	ft_stackclear(&a, ft_free);
}
