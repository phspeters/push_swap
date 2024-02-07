/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:57:55 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/07 13:46:27 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Pushes the top item from the origin stack to the top of the destination
 * stack.
 * 
 * @param origin The stack to be popped from.
 * @param destination The stack to be pushed to.
 */
void	push(t_stack *origin, t_stack *destination)
{
	if (origin->top < 0)
		return ;
	destination->top++;
	destination->items[destination->top].value = \
											origin->items[origin->top].value;
	origin->top--;
}

/**
 * @brief a.k.a Push to A. Calls the push function to push the top item from
 * stack_b to stack_a.
 * 
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param program Flag to check if the function is being called from PUSH_SWAP
 * or CHECKER. If it's push_swap, it will print the operation on the standard 
 * output. Otherwise, it won't.
 */
void	pa(t_stack *stack_a, t_stack *stack_b, int program)
{
	push(stack_b, stack_a);
	if (program == PUSH_SWAP)
		write(1, "pa\n", 3);
}

/**
 * @brief a.k.a Push to B. Calls the push function to push the top item from
 * stack_a to stack_b.
 * 
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param program Flag to check if the function is being called from PUSH_SWAP
 * or CHECKER. If it's push_swap, it will print the operation on the standard 
 * output. Otherwise, it won't.
 */
void	pb(t_stack *stack_a, t_stack *stack_b, int program)
{
	push(stack_a, stack_b);
	if (program == PUSH_SWAP)
		write(1, "pb\n", 3);
}
