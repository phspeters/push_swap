/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:00:58 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/27 20:51:25 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_order(t_stack stack_a, t_stack stack_b)
{
	int	i;

	if (stack_b.top >= 0)
		return (0);
	i = stack_a.top;
	while (i > 0)
	{
		if (((stack_a.items[i].value + 1) % (stack_a.top + 1)) != (stack_a.items[i - 1].value))
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
		while (stack_a->items[i].value != stack_a->top - stack_a->items[i].arr_index)
			ra(stack_a);
	}
	else
	{
		while (stack_a->items[i].value != stack_a->top - stack_a->items[i].arr_index)
			rra(stack_a);
	}
}

int	sorted(t_stack stack_a, t_stack stack_b)
{
	int	i;

	if (stack_b.top != -1)
		return (0);
	i = 0;
	while (i <= stack_a.top)
	{
		if (stack_a.items[i].value != \
		(stack_a.top - stack_a.items[i].arr_index))
			return (0);
		i++;
	}
	return (1);
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
		ra(stack);
	else if (highest == stack->items[stack->top - 1].value)
		rra(stack);
	if (stack->items[stack->top].value > stack->items[stack->top - 1].value)
		sa(stack);
}

void	leave_lis_and_push_rest(t_stack *stack_a, t_stack *stack_b, t_lis lis)
{
	int	i;

	i = 0;
	while (i < lis.size)
	{
		if (stack_a->items[stack_a->top].value == lis.sequence[i])
		{
			ra(stack_a);
			i++;
		}
		else
			pb(stack_a, stack_b);
		if (i > lis.size - 1)
			while (stack_a->items[stack_a->top].value != lis.sequence[0])
				pb(stack_a, stack_b);
	}
	free(lis.sequence);
}

void	leave_only_three(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top > 2)
		pb(stack_a, stack_b);
}

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
			leave_only_three(stack_a, stack_b);
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
