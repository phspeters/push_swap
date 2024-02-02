/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:57:57 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/02 17:26:19 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate(t_stack *stack)
{
	int	swap_value;
	int	i;

	if (stack->top < 1)
		return ;
	swap_value = stack->items[stack->top].value;
	i = stack->top;
	while (i > 0)
	{
		stack->items[i].value = stack->items[i - 1].value;
		i--;
	}
	stack->items[0].value = swap_value;
}

void	ra(t_stack *stack, int program)
{
	rotate(stack);
	if (program == PUSH_SWAP)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int program)
{
	rotate(stack);
	if (program == PUSH_SWAP)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int program)
{
	rotate(stack_a);
	rotate(stack_b);
	if (program == PUSH_SWAP)
		write(1, "rr\n", 3);
}