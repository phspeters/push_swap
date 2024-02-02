/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:17:54 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/02 19:29:53 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define CHECKER 0
# define PUSH_SWAP 1

typedef struct s_arguments
{
	int		size;
	long	*numbers;
}	t_arguments;

typedef struct s_stack_item
{
	int	value;
	int	arr_index;
	int	stack_a_movement_cost;
	int	stack_b_movement_cost;
	int	combined_cost;
}	t_item;

typedef struct s_stack
{
	int		top;
	int		max_size;
	t_item	*items;
}	t_stack;

//stack.c
void		initialize_stacks(t_stack *stack_a, t_stack *stack_b,
				t_arguments arguments);
void		populate_stack(t_stack *stack, t_arguments arguments);
void		rank_and_update_stack_values(t_stack *stack, t_arguments arguments);
int			sorted(t_stack stack_a, t_stack stack_b);
void		calculate_stack_positions(t_stack *stack);

//parsing.c
t_arguments	parse_arguments(int argc, char **argv);
t_arguments	parse_single_argument(char *argv);
t_arguments	parse_multiple_arguments(char **arguments);
int			count_args(char **list);
int			check_for_duplicates_and_int_range(long *list, int size);

//utils.c
int			has_invalid_chars(char *arg);
int			has_invalid_args(char **arg_list);
void		free_data(t_stack *stack_a, t_stack *stack_b,
				t_arguments *arguments);
int			max(int a, int b);
int			min(int a, int b);

//push.c
void		push(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack *stack_a, t_stack *stack_b, int program);
void		pb(t_stack *stack_a, t_stack *stack_b, int program);

//swap.c
void		swap(t_stack *stack);
void		sa(t_stack *stack, int program);
void		sb(t_stack *stack, int program);
void		ss(t_stack *stack_a, t_stack *stack_b, int program);

//rotate.c
void		rotate(t_stack *stack);
void		ra(t_stack *stack, int program);
void		rb(t_stack *stack, int program);
void		rr(t_stack *stack_a, t_stack *stack_b, int program);

//reverse_rotate.c
void		reverse_rotate(t_stack *stack);
void		rra(t_stack *stack, int program);
void		rrb(t_stack *stack, int program);
void		rrr(t_stack *stack_a, t_stack *stack_b, int program);

#endif