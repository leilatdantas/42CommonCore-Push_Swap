/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:20:37 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/06 12:35:17 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_checker_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_check2(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		ft_rra(a, 0);
	else if (line[2] == 'b')
		ft_rrb(b, 0);
	else if (line[2] == 'r')
		ft_rrr(a, b, 0);
}

char	*ft_check(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_pa(a, b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_pb(a, b, 0);
	else if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_sa(a, 0);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_sb(b, 0);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_ss(a, b, 0);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_ra(a, 0);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rb(b, 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rr(a, b, 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[3 == '\n'])
		ft_check2(a, b, line);
	else
		ft_checker_error();
	return (get_next_line(0));
}

void	ft_checker(t_stack **a, char *line)
{
	char	*tmp;
	t_stack	*b;

	b = NULL;
	while(line && *line != '\n')
	{
		tmp = line;
		printf(tmp);
		line = ft_check(a, &b, line);
		free(tmp);
	}
	if (b)
		write(1, "KO\n", 3);
	else if (!check_sort(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	char	*line;

	a = get_stack(argc, argv);
	if (argc <= 1)
		exit(EXIT_FAILURE);
	if (!validate_stack(argc, argv) || !check_repeat(a))
		ft_error_print();
	line = get_next_line(0);
	if (!line && !check_sort(a))
		write(1, "KO\n", 3);
	else if (!line && check_sort(a))
		write(1, "OK\n", 3);
	else
		ft_checker(&a, line);
	ft_stackclear(&a, ft_free);
}