/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:17:54 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/07 16:37:10 by pehenri2         ###   ########.fr       */
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

/**
 * @brief Structure to hold the arguments passed to the program as integers.
 *
 * @param size Size of the array.
 * @param numbers Array of integers.
 * @param is_valid 1 if the arguments are valid, 0 otherwise.
 */
typedef struct s_arguments
{
	int		is_valid;
	int		size;
	long	*numbers;
}	t_arguments;

/**
 * @brief Structure to represent the items of the stack.
 * 
 * @param value Value of the item. Initially, the holds the argument value. Later
 * in the program, it holds the rank of the item.
 * @param arr_index Index of the item in the underlying array, NOT the stack.
 * @param stack_a_movement_cost Cost of moving the target item to the top of
 * stack A.
 * @param stack_b_movement_cost Cost of moving the item to the top of stack B.
 * @param combined_cost Combined cost of moving the item to the top of stack B
 * and the target item to the top of stack A.
 */
typedef struct s_stack_item
{
	int	value;
	int	arr_index;
	int	stack_a_movement_cost;
	int	stack_b_movement_cost;
	int	combined_cost;
}	t_item;

/**
 * @brief Structure to represent the stack.
 *
 * @param top Index of the top of the stack.
 * @param max_size Maximum size of the stack.
 * @param quarters Array of indexes of the elements that divide the items not
 * part of the L.I.S in proportional quarters.
 * @param items Array of items.
 */
typedef struct s_stack
{
	int		top;
	int		max_size;
	int		quarters[3];
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
void		sa(t_stack *stack_a, int program);
void		sb(t_stack *stack_b, int program);
void		ss(t_stack *stack_a, t_stack *stack_b, int program);

//rotate.c

void		rotate(t_stack *stack);
void		ra(t_stack *stack_a, int program);
void		rb(t_stack *stack_b, int program);
void		rr(t_stack *stack_a, t_stack *stack_b, int program);

//reverse_rotate.c

void		reverse_rotate(t_stack *stack);
void		rra(t_stack *stack_a, int program);
void		rrb(t_stack *stack_b, int program);
void		rrr(t_stack *stack_a, t_stack *stack_b, int program);

#endif