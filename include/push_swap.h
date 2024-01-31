/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:13:11 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/31 19:48:20 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct s_longest_increasing_subsequence
{
	int	*sequence;
	int	*size_ending_in_original_index;
	int	*original_index_of_previous_element;
	int	highest_element_original_index;
	int	size;
}	t_lis;

//main.c
void		initialize_stacks(t_stack *stack_a, t_stack *stack_b,
				t_arguments arguments);
void		populate_stack(t_stack *stack, t_arguments arguments);
void		rank_and_update_stack_values(t_stack *stack, t_arguments arguments);

//parsing.c
t_arguments	parse_arguments(int argc, char **argv);
t_arguments	parse_single_argument(char *argv);
t_arguments	parse_multiple_arguments(char **arguments);
int			count_args(char **list);
int			check_for_duplicates_and_int_range(long *list, int size);

//sort.c
int			sorted(t_stack stack_a, t_stack stack_b);
void		sort(t_stack *stack_a, t_stack *stack_b);
void		sort_three_numbers(t_stack *stack);
int			in_order(t_stack stack_a, t_stack stack_b);
void		rotate_until_sorted(t_stack *stack_a);

//lis.c
t_lis		get_lis(t_stack *stack);
void		initialize_lis_parameters(t_lis *lis, t_stack stack);
int			*get_lis_numbers(t_item *items, t_lis *lis);
void		update_lis_parameters(t_lis *lis, int i, int j);
void		leave_lis_and_push_rest(t_stack *stack_a, t_stack *stack_b,
				t_lis lis);

//cost.c
t_item		calculate_movement_costs(t_stack *stack_a, t_stack *stack_b);
int			get_stack_a_movement_cost(t_item item_b, t_stack *stack_a);
t_item		get_target_item(t_item item_b, t_stack *stack_a);
int			get_stack_b_movement_cost(t_item item, t_stack *stack_b);
int			get_combined_movement_cost(t_item item);

//move.c
void		make_cheapest_move(t_item cheapest_item, t_stack *stack_a,
				t_stack *stack_b);
void		rotate_and_update_costs(t_stack *stack_a, t_stack *stack_b,
				t_item *item);
void		reverse_rotate_and_update_costs(t_stack *stack_a, t_stack *stack_b,
				t_item *item);
void		update_costs(int *stack_a_movement_cost,
				int *stack_b_movement_cost);

//utils.c
long		ft_atol(const char *nptr);
void		free_data(t_stack *stack_a, t_stack *stack_b,
				t_arguments *arguments);
void		calculate_stack_positions(t_stack *stack);
int			max(int a, int b);
int			min(int a, int b);

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
