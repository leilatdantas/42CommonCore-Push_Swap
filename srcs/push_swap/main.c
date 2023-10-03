/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:22:43 by lebarbos          #+#    #+#             */
/*   Updated: 2023/10/03 15:53:30 by lebarbos         ###   ########.fr       */
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
		j = ft_atoi2(argv[i]);
		ft_stackadd_back(&a, ft_stack_new(j));
		i++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	
	// a = NULL;
	a = get_stack(argc, argv);
	if (argc <= 1)
	{
		write(1, "Error\n", 7);
		exit(1);
	}
	if(!validate_stack(argc, argv))
	{
		write(1, "Error\n", 7);
		exit(1);
	}
	// else
	if(!check_repeat(a))
	{
		write(1, "Error\n", 7);
		exit(1);
	}
	test_print(a);
	// ft_stackclear()
}
