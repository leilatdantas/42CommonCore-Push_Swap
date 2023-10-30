/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:55:49 by lebarbos          #+#    #+#             */
/*   Updated: 2023/10/29 18:56:55 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# include <stdio.h>

typedef struct s_stack
{
	long			nbr;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*Utils*/
void	ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stack_last(t_stack *stack);
t_stack	*ft_stack_new(long content);
int		ft_stack_size(t_stack *stack);
bool	check_repeat(t_stack *a);
void	ft_stackclear(t_stack **stack, void (*del)(void*));
void	ft_free(void *x);
void	ft_stackdelone(t_stack *stack, void (*del)(void*));
void	ft_error_print(t_stack **a);

bool	validate_stack(int argc, char **argv);
void	ft_sa(t_stack **a, int print);
void	ft_sb(t_stack **b, int print);
void	ft_ss(t_stack **a, t_stack **b, int print);
void	ft_ra(t_stack **a, int print);
void	ft_rr(t_stack **a, t_stack **b, int print);
void	ft_rra(t_stack **a, int print);

void	test_print(t_stack *a);

#endif