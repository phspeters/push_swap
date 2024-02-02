/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:03:05 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/02 17:33:50 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
