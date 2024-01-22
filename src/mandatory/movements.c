/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:13:52 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/22 18:39:13 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_stack_element	swap_temp;

	if (stack->top < 1)
		return ;
	swap_temp = stack->list[stack->top];
	stack->list[stack->top] = stack->list[stack->top - 1];
	stack->list[stack->top - 1] = swap_temp;
}

void	push(t_stack *origin, t_stack *destination)
{
	if (origin->top < 0)
		return ;
	destination->top++;
	destination->list[destination->top] = origin->list[origin->top];
	origin->top--;
}

void	rotate(t_stack *stack)
{
	t_stack_element	swap_temp;
	int				i;

	if (stack->top < 1)
		return ;
	swap_temp = stack->list[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->list[i] = stack->list[i - 1];
		i--;
	}
	stack->list[0] = swap_temp;
}

void	reverse_rotate(t_stack *stack)
{
	t_stack_element	swap_temp;
	int				i;

	if (stack->top < 1)
		return ;
	swap_temp = stack->list[0];
	i = 0;
	while (i < stack->top)
	{
		stack->list[i] = stack->list[i + 1];
		i++;
	}
	stack->list[stack->top] = swap_temp;
}
