/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:57:23 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/06 15:32:08 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Swaps the top two elements of the stack.
 * 
 * @param stack Pointer to the stack to be swapped.
 */
void	swap(t_stack *stack)
{
	int	value_swap;

	if (stack->top < 1)
		return ;
	value_swap = stack->items[stack->top].value;
	stack->items[stack->top].value = stack->items[stack->top - 1].value;
	stack->items[stack->top - 1].value = value_swap;
}

/**
 * @brief Calls the swap function to swap stack_a.
 * 
 * @param stack_a Pointer to stack A.
 * @param program Flag to check if the function is being called from PUSH_SWAP
 * or CHECKER. If it's push_swap, it will print the operation on the standard
 * output. Otherwise, it won't.
 */
void	sa(t_stack *stack_a, int program)
{
	swap(stack_a);
	if (program == PUSH_SWAP)
		write(1, "sa\n", 3);
}

/**
 * @brief Calls the swap function to swap stack_b.
 * 
 * @param stack_b Pointer to stack B.
 * @param program Flag to check if the function is being called from PUSH_SWAP
 * or CHECKER. If it's push_swap, it will print the operation on the standard
 * output. Otherwise, it won't.
 */
void	sb(t_stack *stack_b, int program)
{
	swap(stack_b);
	if (program == PUSH_SWAP)
		write(1, "sb\n", 3);
}

/**
 * @brief Calls the swap function to swap stack_a and stack_b.
 * 
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param program Flag to check if the function is being called from PUSH_SWAP
 * or CHECKER. If it's push_swap, it will print the operation on the standard
 * output. Otherwise, it won't.
 */
void	ss(t_stack *stack_a, t_stack *stack_b, int program)
{
	swap(stack_a);
	swap(stack_b);
	if (program == PUSH_SWAP)
		write(1, "ss\n", 3);
}
