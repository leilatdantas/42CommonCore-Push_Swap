/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:22:43 by lebarbos          #+#    #+#             */
/*   Updated: 2023/10/05 19:18:20 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack *get_stack(int argc, char **argv)
{
	int i;
	t_stack *a;
	int	j;
	
	i = 1;
	a = NULL;
	while (i < argc)
	{
		j = ft_atoi(argv[i]);
		ft_stackadd_back(&a, ft_stack_new(j));
		i++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	
	a = get_stack(argc, argv);
	if (argc <= 1 || !validate_stack(argc, argv) || !check_repeat(a))
		ft_error_print(&a);
	test_print(a);
	ft_stackclear(&a, ft_free);
}
