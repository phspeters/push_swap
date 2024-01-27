/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:58:35 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/27 20:49:12 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_item	get_target_item(t_item item_b, t_stack *stack_a)
{
	t_item	lowest;
	int		i;
	int		j;

	lowest.value = INT_MAX;
	i = 1;
	while (i <= 500)
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

int	get_stack_b_movement_cost(t_item item, t_stack *stack_b)
{
	int	rotate;
	int	reverse_rotate;

	rotate = stack_b->top - item.arr_index;
	reverse_rotate = -1 - item.arr_index;
	if (rotate < abs(reverse_rotate))
		return (rotate);
	else
		return (reverse_rotate);
}

int	get_total_movement_cost(t_item item)
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

t_item	calculate_movement_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_item	cheapest_item;
	int		index;
	int		cheapest_move;

	cheapest_move = INT_MAX;
	index = stack_b->top;
	while (index >= 0)
	{
		stack_b->items[index].stack_a_movement_cost = get_stack_a_movement_cost(stack_b->items[index], stack_a);
		stack_b->items[index].stack_b_movement_cost = get_stack_b_movement_cost(stack_b->items[index], stack_b);
		stack_b->items[index].combined_cost = get_total_movement_cost(stack_b->items[index]);
		if (abs(stack_b->items[index].combined_cost) < cheapest_move)
		{
			cheapest_move = stack_b->items[index].combined_cost;
			cheapest_item = stack_b->items[index];
		}
		index--;
	}
	return (cheapest_item);
}
