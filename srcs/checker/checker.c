/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:20:37 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/10 12:06:56 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_checker_error(t_stack *a)
{
	write(2, "Error\n", 6);
	ft_stackclear(&a, ft_free);
	exit(EXIT_FAILURE);
}

bool	ft_check_aux(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		ft_rra(a, 0);
	else if (line[2] == 'b')
		ft_rrb(b, 0);
	else if (line[2] == 'r')
		ft_rrr(a, b, 0);
	else
		return (false);
	return (true);
}

bool	ft_check_and_execute(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 'p' && line[1] == 'a' && line[2] == '\0')
		ft_pa(a, b, 0);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\0')
		ft_pb(a, b, 0);
	else if (line[0] == 's' && line[1] == 'a' && line[2] == '\0')
		ft_sa(a, 0);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\0')
		ft_sb(b, 0);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\0')
		ft_ss(a, b, 0);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\0')
		ft_ra(a, 0);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\0')
		ft_rb(b, 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\0')
		ft_rr(a, b, 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\0')
		return (ft_check_aux(a, b, line));
	else
		return (false);
	return (true);
}

void	check_line(t_stack **a, t_stack **b)
{
	int		i;
	char	*line;
	char	c;

	i = 0;
	line = malloc(4);
	while (read(0, &c, 1))
	{
		if (c == '\n' || i >= 3)
		{
			line[i] = '\0';
			if (!ft_check_and_execute(a, b, line))
			{
				free(line);
				ft_stackclear(b, ft_free);
				ft_checker_error(*a);
			}
			free(line);
			line = malloc(4);
			i = 0;
		}
		else
			line[i++] = c;
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!validate_stack(argc, argv))
		ft_error();
	if (argc <= 1)
		exit(EXIT_FAILURE);
	a = get_stack_ch(argc, argv);
	b = NULL;
	if (!check_repeat(a))
		ft_checker_error(a);
	check_line(&a, &b);
	if (!b && check_sort(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_stackclear(&a, ft_free);
	return (0);
}
