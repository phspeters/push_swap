/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:00:58 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/24 18:58:09 by pehenri2         ###   ########.fr       */
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
		if (stack->list[i].value > highest)
			highest = stack->list[i].value;
		i++;
	}
	if (highest == stack->list[stack->top].value)
		ra(stack);
	else if (highest == stack->list[stack->top - 1].value)
		rra(stack);
	if (stack->list[stack->top].value > stack->list[stack->top - 1].value)
		sa(stack);
}

int	*get_lis(t_stack *stack)
{
	int	*temp;

	temp = NULL;
	(void)stack;
	return (temp);
}

void	leave_lis_and_push_rest(t_stack *stack_a, t_stack *stack_b, int *lis)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (stack_a->list[stack_a->top].value == lis[i])
		{
			ra(stack_a);
			i++;
		}
		else
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
	int	*lis;

	if (stack_a->top < 3)
		sort_three_numbers(stack_a);
	else
	{
		lis = get_lis(stack_a);
		if (lis)
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
