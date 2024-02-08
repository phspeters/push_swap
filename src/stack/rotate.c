/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:57:57 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/08 14:31:54 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Shifts up all elements of the stack by 1 position. The last element
 * becomes the first one.
 * 
 * @param stack Pointer to the stack to be rotated.
 */
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

/**
 * @brief a.k.a Rotate A. Calls the rotate function to shift up all elements of
 * stack A by 1 position. The last element becomes the first one.
 * 
 * @param stack_a Pointer to stack A.
 * @param program Flag to check if the function is being called from PUSH_SWAP
 * or CHECKER. If it's push_swap, it will print the operation on the standard
 * output. Otherwise, it won't.
 */
void	ra(t_stack *stack_a, int program)
{
	rotate(stack_a);
	if (program == PUSH_SWAP)
		write(1, "ra\n", 3);
}

/**
 * @brief a.k.a Rotate B. Calls the rotate function to shift up all elements of
 * stack B by 1 position. The last element becomes the first one.
 * 
 * @param stack_b Pointer to stack B.
 * @param program Flag to check if the function is being called from PUSH_SWAP
 * or CHECKER. If it's push_swap, it will print the operation on the standard
 * output. Otherwise, it won't.
 */
void	rb(t_stack *stack_b, int program)
{
	rotate(stack_b);
	if (program == PUSH_SWAP)
		write(1, "rb\n", 3);
}

/**
 * @brief Calls the rotate function to shift up all elements of both stacks by
 * 1 position with a single instruction. The last element in each stack becomes
 * the first one.
 * 
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param program Flag to check if the function is being called from PUSH_SWAP
 * or CHECKER. If it's push_swap, it will print the operation on the standard
 * output. Otherwise, it won't.
 */
void	rr(t_stack *stack_a, t_stack *stack_b, int program)
{
	rotate(stack_a);
	rotate(stack_b);
	if (program == PUSH_SWAP)
		write(1, "rr\n", 3);
}
