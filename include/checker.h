/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:32:10 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/01 18:23:57 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

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

//main.c
void		initialize_stacks(t_stack *stack_a, t_stack *stack_b,
				t_arguments arguments);
void		populate_stack(t_stack *stack, t_arguments arguments);
int			sorted(t_stack stack_a, t_stack stack_b);

//parsing.c
t_arguments	parse_arguments(int argc, char **argv);
t_arguments	parse_single_argument(char *argv);
t_arguments	parse_multiple_arguments(char **arguments);
int			count_args(char **list);
int			check_for_duplicates_and_int_range(long *list, int size);

//instructions.c
void		read_and_apply_instructions(t_stack *stack_a, t_stack *stack_b);
void		apply_instructions(char *instruction, t_stack *stack_a,
				t_stack *stack_b);
//utils.c
long		ft_atol(const char *nptr);
void		free_data(t_stack *stack_a, t_stack *stack_b,
				t_arguments *arguments);
void		calculate_stack_positions(t_stack *stack);

//push.c
void		push(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);

//swap.c
void		swap(t_stack *stack);
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack_a, t_stack *stack_b);

//rotate.c
void		rotate(t_stack *stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack_a, t_stack *stack_b);

//reverse_rotate.c
void		reverse_rotate(t_stack *stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack_a, t_stack *stack_b);

#endif