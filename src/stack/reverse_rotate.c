/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:58:00 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/06 15:29:39 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Rotates the stack down by one position. The last element becomes
 * the first one.
 * 
 * @param stack Pointer to the stack to be reversed rotated.
 */
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

/**
 * @brief Calls the reverse_rotate function to reverse rotate stack_a.
 * 
 * @param stack_a Pointer to stack A.
 * @param program Flag to check if the function is being called from PUSH_SWAP
 * or CHECKER. If it's push_swap, it will print the operation on the standard
 * output. Otherwise, it won't.
 */
void	rra(t_stack *stack_a, int program)
{
	reverse_rotate(stack_a);
	if (program == PUSH_SWAP)
		write(1, "rra\n", 4);
}

/**
 * @brief Calls the reverse_rotate function to reverse rotate stack_b.
 * 
 * @param stack_b Pointer to stack B.
 * @param program Flag to check if the function is being called from PUSH_SWAP
 * or CHECKER. If it's push_swap, it will print the operation on the standard
 * output. Otherwise, it won't.
 */
void	rrb(t_stack *stack_b, int program)
{
	reverse_rotate(stack_b);
	if (program == PUSH_SWAP)
		write(1, "rrb\n", 4);
}

/**
 * @brief Calls the reverse_rotate function to reverse rotate both stacks.
 * 
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param program Flag to check if the function is being called from PUSH_SWAP
 * or CHECKER. If it's push_swap, it will print the operation on the standard
 * output. Otherwise, it won't.
 */
void	rrr(t_stack *stack_a, t_stack *stack_b, int program)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (program == PUSH_SWAP)
		write(1, "rrr\n", 4);
}
