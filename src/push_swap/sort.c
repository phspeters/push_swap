/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:00:58 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/02 17:34:04 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_lis	lis;
	t_item	cheapest;

	if (stack_a->top < 3)
		sort_three_numbers(stack_a);
	else
	{
		lis = get_lis(stack_a);
		if (lis.sequence)
			leave_lis_and_push_rest(stack_a, stack_b, lis);
		else
		{
			while (stack_a->top > 2)
				pb(stack_a, stack_b, PUSH_SWAP);
			sort_three_numbers(stack_a);
		}
		calculate_stack_positions(stack_b);
		while (!in_order(*stack_a, *stack_b))
		{
			cheapest = calculate_movement_costs(stack_a, stack_b);
			make_cheapest_move(cheapest, stack_a, stack_b);
		}
		if (!sorted(*stack_a, *stack_b))
			rotate_until_sorted(stack_a);
	}
}

void	sort_three_numbers(t_stack *stack)
{
	int	highest;
	int	i;

	highest = -1;
	i = 0;
	while (i <= stack->top)
	{
		if (stack->items[i].value > highest)
			highest = stack->items[i].value;
		i++;
	}
	if (highest == stack->items[stack->top].value)
		ra(stack, PUSH_SWAP);
	else if (highest == stack->items[stack->top - 1].value)
		rra(stack, PUSH_SWAP);
	if (stack->items[stack->top].value > stack->items[stack->top - 1].value)
		sa(stack, PUSH_SWAP);
}

int	in_order(t_stack stack_a, t_stack stack_b)
{
	int	i;

	if (stack_b.top >= 0)
		return (0);
	i = stack_a.top;
	while (i > 0)
	{
		if (((stack_a.items[i].value + 1) % (stack_a.top + 1))
			!= (stack_a.items[i - 1].value))
			return (0);
		i--;
	}
	return (1);
}

void	rotate_until_sorted(t_stack *stack_a)
{
	int	i;
	int	middle;

	middle = stack_a->top / 2;
	i = stack_a->top;
	while (i >= 0)
	{
		if (stack_a->items[i].value == 0)
			break ;
		i--;
	}
	if (stack_a->items[i].arr_index >= middle)
	{
		while (stack_a->items[i].value
			!= stack_a->top - stack_a->items[i].arr_index)
			ra(stack_a, PUSH_SWAP);
	}
	else
	{
		while (stack_a->items[i].value
			!= stack_a->top - stack_a->items[i].arr_index)
			rra(stack_a, PUSH_SWAP);
	}
}
