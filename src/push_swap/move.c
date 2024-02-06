/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:03:05 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/06 17:05:36 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Chooses the moves to be made based on the costs of the cheapest item.
 * If the cost for both stacks is positive, the function rotates both stacks 
 * with rr. If the cost for both stacks is negative, the function reverse
 * rotates both stacks with rrr. Otherwise, the function first moves the stack_a,
 * then the stack_b.
 * 
 * 
 * @param cheapest_item 
 * @param stack_a 
 * @param stack_b 
 */
void	make_cheapest_move(t_item cheapest_item, t_stack *stack_a,
	t_stack *stack_b)
{
	int	i;
	int	abs_cost;

	abs_cost = abs(cheapest_item.combined_cost);
	i = 0;
	while (i < abs_cost)
	{
		if ((cheapest_item.stack_a_movement_cost > 0)
			&& (cheapest_item.stack_b_movement_cost > 0))
			rotate_and_update_costs(stack_a, stack_b, &cheapest_item);
		else if ((cheapest_item.stack_a_movement_cost < 0)
			&& (cheapest_item.stack_b_movement_cost < 0))
			reverse_rotate_and_update_costs(stack_a, stack_b, &cheapest_item);
		else if (cheapest_item.stack_a_movement_cost > 0)
			rotate_and_update_costs(stack_a, NULL, &cheapest_item);
		else if (cheapest_item.stack_a_movement_cost < 0)
			reverse_rotate_and_update_costs(stack_a, NULL, &cheapest_item);
		else if (cheapest_item.stack_b_movement_cost > 0)
			rotate_and_update_costs(NULL, stack_b, &cheapest_item);
		else if (cheapest_item.stack_b_movement_cost < 0)
			reverse_rotate_and_update_costs(NULL, stack_b, &cheapest_item);
		i++;
	}
	pa(stack_a, stack_b, PUSH_SWAP);
}

/**
 * @brief Rotates the stacks passed as arguments and updates the costs to get
 * the item in stack B in it's proper position on stack A, based on the
 * movements made.
 * 
 * @param stack_a Pointer to the stack_a or NULL.
 * @param stack_b Pointer to the stack_b or NULL.
 */
void	rotate_and_update_costs(t_stack *stack_a, t_stack *stack_b,
	t_item *item)
{
	if (stack_a && stack_b)
	{
		rr(stack_a, stack_b, PUSH_SWAP);
		update_costs(&item->stack_a_movement_cost,
			&item->stack_b_movement_cost);
	}
	else if (stack_a)
	{
		ra(stack_a, PUSH_SWAP);
		update_costs(&item->stack_a_movement_cost, NULL);
	}
	else if (stack_b)
	{
		rb(stack_b, PUSH_SWAP);
		update_costs(NULL, &item->stack_b_movement_cost);
	}
}

/**
 * @brief Reverse rotates the stacks passed as arguments and updates the costs 
 * to get the item in stack B in it's proper position on stack A, based on the
 * movements made.
 * 
 * @param stack_a Pointer to the stack_a or NULL.
 * @param stack_b Pointer to the stack_b or NULL.
 */
void	reverse_rotate_and_update_costs(t_stack *stack_a, t_stack *stack_b,
	t_item *item)
{
	if (stack_a && stack_b)
	{
		rrr(stack_a, stack_b, PUSH_SWAP);
		update_costs(&item->stack_a_movement_cost,
			&item->stack_b_movement_cost);
	}
	else if (stack_a)
	{
		rra(stack_a, PUSH_SWAP);
		update_costs(&item->stack_a_movement_cost, NULL);
	}
	else if (stack_b)
	{
		rrb(stack_b, PUSH_SWAP);
		update_costs(NULL, &item->stack_b_movement_cost);
	}
}

/**
 * @brief Updates the costs of moving the desired item in stack B to the top
 * and the target item in stack A to the top of stack A. If the cost is positive,
 * the cost is decremented by 1. If the cost is negative, the cost is incremented
 * by 1. Should be called after the movement is made.
 * 
 * @param stack_a_movement_cost Pointer to the cost of moving stack A or NULL.
 * @param stack_b_movement_cost Pointer to the cost of moving stack B or NULL.
 */
void	update_costs(int *stack_a_movement_cost, int *stack_b_movement_cost)
{
	if (stack_a_movement_cost)
	{
		if (*stack_a_movement_cost > 0)
			(*stack_a_movement_cost)--;
		else if (*stack_a_movement_cost < 0)
			(*stack_a_movement_cost)++;
	}
	if (stack_b_movement_cost)
	{
		if (*stack_b_movement_cost > 0)
			(*stack_b_movement_cost)--;
		else if (*stack_b_movement_cost < 0)
			(*stack_b_movement_cost)++;
	}
}
