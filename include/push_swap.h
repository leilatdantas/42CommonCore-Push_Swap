/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:55:49 by lebarbos          #+#    #+#             */
/*   Updated: 2023/11/10 10:35:24 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	long			nbr;
	int				index;
	int				cost;
	bool			above_median;
	bool			min_cost;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

/*algorithm.c*/
void	ft_sort(t_stack **a);
void	ft_big_sort(t_stack **a);
void	ft_sort_three(t_stack **a);

/*calculate_cost*/
void	calculate_cost(t_stack *src, t_stack *dst);
void	set_min_cost(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);
void	update_cost(t_stack *src, int size_src, int size_dst);

/*error*/
void	ft_free(void *x);
void	ft_error_print(t_stack *a);
void	ft_error(void);

/*operations*/
void	ft_pa(t_stack **a, t_stack **b, int print);
void	ft_pb(t_stack **b, t_stack **a, int print);
void	ft_sa(t_stack **a, int print);
void	ft_sb(t_stack **b, int print);
void	ft_ss(t_stack **a, t_stack **b, int print);
void	ft_ra(t_stack **a, int print);
void	ft_rb(t_stack **b, int print);
void	ft_rr(t_stack **a, t_stack **b, int print);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	ft_rra(t_stack **a, int print);
void	ft_rrb(t_stack **b, int print);
void	ft_rrr(t_stack **a, t_stack **b, int print);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);

/*sorting_aux*/
int		check_bellow_target(t_stack *a, int target);
void	pre_push(t_stack **stack, t_stack *cheapest, char k);
void	set_index(t_stack *stack);
void	set_target(t_stack *src, t_stack *dst);
t_stack	*find_bellow(t_stack *a, int target);

/*sorting*/
void	ft_move_to_a(t_stack **src, t_stack **dst);
void	ft_move_to_b(t_stack **a, t_stack **b);
void	init_stack_b(t_stack *b, t_stack *a);

/*stack_aux*/
t_stack	*ft_stack_new(long content);
t_stack	*ft_stack_last(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
int		ft_stack_size(t_stack *stack);

/*Utils*/
t_stack	*get_stack(int argc, char **argv);
long	ft_min(t_stack *a);
long	ft_max(t_stack *a);
void	ft_stackclear(t_stack **stack, void (*del)(void*));
t_stack	*ft_find_node(t_stack *stack, long nbr);

/*validate*/
bool	check_sort(t_stack *a);
bool	check_repeat(t_stack *a);
bool	check_number(char *nbr);
bool	validate_stack(int argc, char **argv);

/*checker*/
t_stack	*get_stack_ch(int argc, char **argv);

void	ft_checker(t_stack **a, t_stack **b);
void	ft_checker_error(t_stack *a);

#endif