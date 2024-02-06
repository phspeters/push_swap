/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:13:11 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/06 17:47:34 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

/**
 * @brief Structure to hold the longest increasing subsequence of the
 * stack and it's parameters.
 * 
 * @param sequence Array of the longest increasing subsequence.
 * @param size_ending_in_original_index Array of the size of the longest
 * increasing subsequence ending in the given index of the original array.
 * @param original_index_of_previous_element Array of the index of the previous
 * element in the longest increasing subsequence.
 * @param highest_element_original_index Index of the highest element that
 * is part of the longest increasing subsequence.
 * @param size Size of the longest increasing subsequence.
 */
typedef struct s_longest_increasing_subsequence
{
	int	*sequence;
	int	*size_ending_in_original_index;
	int	*original_index_of_previous_element;
	int	highest_element_original_index;
	int	size;
}	t_lis;

//sort.c

void		sort(t_stack *stack_a, t_stack *stack_b);
void		sort_three_numbers(t_stack *stack);
int			in_order(t_stack stack_a, t_stack stack_b);
void		rotate_until_sorted(t_stack *stack_a);
void		selection_sort(int *remaining, int size);

//lis.c

t_lis		get_lis(t_stack *stack);
void		initialize_lis_parameters(t_lis *lis, t_stack stack);
void		update_lis_parameters(t_lis *lis, int i, int j);
int			*get_lis_numbers(t_item *items, t_lis *lis);
int			part_of_lis(t_item item, t_lis lis);

//lis_operations.c

void		leave_lis_and_push_rest(t_stack *stack_a, t_stack *stack_b,
				t_lis lis);
int			*get_remaining_elements(t_stack *stack, t_lis lis);
void		find_quarters(t_stack *stack, int *remaining, int size);
void		push_lower_half_and_pre_sort(t_stack *stack_a, t_stack *stack_b,
				t_lis lis);
void		push_rest_and_pre_sort(t_stack *stack_a, t_stack *stack_b,
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

#endif
