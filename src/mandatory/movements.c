/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:13:52 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/23 14:41:26 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	value_swap;

	if (stack->top < 1)
		return ;
	value_swap = stack->list[stack->top].value;
	stack->list[stack->top].value = stack->list[stack->top - 1].value;
	stack->list[stack->top - 1].value = value_swap;
}

void	push(t_stack *origin, t_stack *destination)
{
	if (origin->top < 0)
		return ;
	destination->top++;
	destination->list[destination->top].value = origin->list[origin->top].value;
	origin->top--;
}

void	rotate(t_stack *stack)
{
	int	swap_value;
	int	i;

	if (stack->top < 1)
		return ;
	swap_value = stack->list[stack->top].value;
	i = stack->top;
	while (i > 0)
	{
		stack->list[i].value = stack->list[i - 1].value;
		i--;
	}
	stack->list[0].value = swap_value;
}

void	reverse_rotate(t_stack *stack)
{
	int	swap_value;
	int	i;

	if (stack->top < 1)
		return ;
	swap_value = stack->list[0].value;
	i = 0;
	while (i < stack->top)
	{
		stack->list[i].value = stack->list[i + 1].value;
		i++;
	}
	stack->list[stack->top].value = swap_value;
}
