/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:57:55 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/02 17:24:47 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack *origin, t_stack *destination)
{
	if (origin->top < 0)
		return ;
	destination->top++;
	destination->items[destination->top].value = \
											origin->items[origin->top].value;
	origin->top--;
}

void	pa(t_stack *stack_a, t_stack *stack_b, int program)
{
	push(stack_b, stack_a);
	if (program == PUSH_SWAP)
		write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b, int program)
{
	push(stack_a, stack_b);
	if (program == PUSH_SWAP)
		write(1, "pb\n", 3);
}