/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:00:58 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/25 14:11:16 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_lis	get_lis(t_stack *stack)
{
	t_lis	temp;

	temp.size = 0;
	(void)stack;
	return (temp);
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
}

void	leave_only_three(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top > 3)
		pb(stack_a, stack_b);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_lis	lis;

	if (stack_a->top < 3)
		sort_three_numbers(stack_a);
	else
	{
		lis = get_lis(stack_a);
		if (lis.sequence)
			leave_lis_and_push_rest(stack_a, stack_b, lis);
		else
			leave_only_three(stack_a, stack_b);
		while (!sorted(stack_a, stack_b))
		{
			calculate_movement_costs(stack_a, stack_a);
			make_cheapest_move(stack_a, stack_b);
		}
	}
}
