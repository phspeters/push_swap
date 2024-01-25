/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:58:00 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/25 13:45:08 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rra(t_stack *stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
