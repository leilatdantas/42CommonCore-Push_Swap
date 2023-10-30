/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:22:43 by lebarbos          #+#    #+#             */
/*   Updated: 2023/10/30 09:50:10 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*get_stack(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	int		j;

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

bool	check_sort(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->nbr < a->nbr)
				return (false);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;

	b = NULL;
	a = get_stack(argc, argv);
	if (argc <= 1)
		exit(1);
	if (!validate_stack(argc, argv) || !check_repeat(a))
		ft_error_print(&a);
	if (!check_sort(a))
	{
		test_print(a);
		printf("\n\n");
		// ft_sa(&a, 1);
		// test_print(a);
		// printf("\n");
		// ft_sb(&a, 1);
		// test_print(a);
		ft_pb(&a, &b, 1);
		test_print(a);
		printf("\n");
		test_print(b);
		printf("\n");
	}
	ft_stackclear(&a, ft_free);
	ft_stackclear(&b, ft_free);
}
