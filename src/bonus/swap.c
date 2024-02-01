/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:57:23 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/01 14:05:43 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_stack *stack)
{
	int	value_swap;

	if (stack->top < 1)
		return ;
	value_swap = stack->items[stack->top].value;
	stack->items[stack->top].value = stack->items[stack->top - 1].value;
	stack->items[stack->top - 1].value = value_swap;
}

void	sa(t_stack *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
