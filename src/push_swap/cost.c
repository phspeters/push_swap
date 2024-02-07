/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:58:35 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/07 13:53:20 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculates the movement costs for each item in stack B to be pushed
 * to stack A while keeping Stack A sorted and returns the cheapest one.
 * 
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @return t_item Cheapest item to be moved.
 */
t_item	calculate_movement_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_item	cheapest_item;
	int		cheapest_move;
	int		index;

	cheapest_move = INT_MAX;
	index = stack_b->top;
	while (index >= 0)
	{
		stack_b->items[index].stack_a_movement_cost
			= get_stack_a_movement_cost(stack_b->items[index], stack_a);
		stack_b->items[index].stack_b_movement_cost
			= get_stack_b_movement_cost(stack_b->items[index], stack_b);
		stack_b->items[index].combined_cost
			= get_combined_movement_cost(stack_b->items[index]);
		if (abs(stack_b->items[index].combined_cost) < abs(cheapest_move))
		{
			cheapest_move = stack_b->items[index].combined_cost;
			cheapest_item = stack_b->items[index];
		}
		index--;
	}
	return (cheapest_item);
}

/**
 * @brief Given an item from Stack B, calculates the movement cost to put the
 * target item of stack A on top of the stack. The target item is the very next
 * item in the sequence of numbers that should be in stack A when it is sorted.
 * 
 * @param item_b The item in stack B.
 * @param stack_a Pointer to stack A.
 * @return Cheapest movement cost for the target item to be on top of
 * stack A. Positive values mean the number of rotates, negative values mean
 * the number of reverse rotates.
 */
int	get_stack_a_movement_cost(t_item item_b, t_stack *stack_a)
{
	t_item	target_item;
	int		rotate;
	int		reverse_rotate;

	target_item = get_target_item(item_b, stack_a);
	rotate = stack_a->top - target_item.arr_index;
	reverse_rotate = -1 - target_item.arr_index;
	if (rotate <= abs(reverse_rotate))
		return (rotate);
	else
		return (reverse_rotate);
}

/**
 * @brief Given an item from Stack B, returns the respective target item from
 * Stack A. The target item is the very next item in the sequence of numbers
 * that should be in stack A when it is sorted.
 * 
 * @param item_b The item in stack B.
 * @param stack_a Pointer to stack A.
 * @return t_item The target item from stack A.
 */
t_item	get_target_item(t_item item_b, t_stack *stack_a)
{
	t_item	lowest;
	int		i;
	int		j;

	lowest.value = INT_MAX;
	i = 1;
	while (i <= stack_a->max_size)
	{
		j = stack_a->top;
		while (j >= 0)
		{
			if (stack_a->items[j].value == item_b.value + i)
				return (stack_a->items[j]);
			if (stack_a->items[j].value < lowest.value)
				lowest = stack_a->items[j];
			j--;
		}
		i++;
	}
	return (lowest);
}

/**
 * @brief Given an item from Stack B, calculates the movement cost to put it
 *  on top of the stack.
 * 
 * @param item The item in stack B.
 * @param stack_b Pointer to stack B.
 * @return Cheapest movement cost for the item to be on top of stack B.
 * Positive values mean the number of rotates, negative values mean the
 * number of reverse rotates.
 */
int	get_stack_b_movement_cost(t_item item, t_stack *stack_b)
{
	int	rotate;
	int	reverse_rotate;

	rotate = stack_b->top - item.arr_index;
	reverse_rotate = -1 - item.arr_index;
	if (rotate <= abs(reverse_rotate))
		return (rotate);
	else
		return (reverse_rotate);
}

/**
 * @brief Given an item from Stack B, returns the combined movement cost to
 * put it on top of stack B and the respective target item on top of stack A.
 * The target item is the very next  * item in the sequence of numbers that
 * should be in stack A when sorted.
 * 
 * @param item The item in stack B.
 * @return The combined movement cost to put it on top of stack A and stack B.
 */
int	get_combined_movement_cost(t_item item)
{
	int	cost_a;
	int	cost_b;

	cost_a = item.stack_a_movement_cost;
	cost_b = item.stack_b_movement_cost;
	if (cost_a >= 0 && cost_b >= 0)
		return (max(cost_a, cost_b));
	else if (cost_a <= 0 && cost_b <= 0)
		return (min(cost_a, cost_b));
	else
		return (abs(cost_a) + abs(cost_b));
}
