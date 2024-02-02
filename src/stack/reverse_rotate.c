/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:58:00 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/02 17:25:13 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	reverse_rotate(t_stack *stack)
{
	int	swap_value;
	int	i;

	if (stack->top < 1)
		return ;
	swap_value = stack->items[0].value;
	i = 0;
	while (i < stack->top)
	{
		stack->items[i].value = stack->items[i + 1].value;
		i++;
	}
	stack->items[stack->top].value = swap_value;
}

void	rra(t_stack *stack, int program)
{
	reverse_rotate(stack);
	if (program == PUSH_SWAP)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int program)
{
	reverse_rotate(stack);
	if (program == PUSH_SWAP)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int program)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (program == PUSH_SWAP)
		write(1, "rrr\n", 4);
}
