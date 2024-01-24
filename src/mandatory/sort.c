/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:00:58 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/24 18:32:42 by pehenri2         ###   ########.fr       */
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

void	sort_with_lis(t_stack *stack_a, t_stack *stack_b, int *lis)
{
	(void)stack_a;
	(void)stack_b;
	(void)lis;
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	*lis;

	if (stack_a->top < 3)
		sort_three_numbers(stack_a);
	else
	{
		lis = get_lis(stack_a);
		sort_with_lis(stack_a, stack_b, lis);
	}
}
