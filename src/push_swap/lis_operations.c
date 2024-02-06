/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 09:46:37 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/06 16:19:07 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Pushes all the elements that are not part of the Longest Increasing
 * Subsequence to stack B and pre-sorts them. First pushes the elements that are
 * part of the lower half of the remaining elements, then the elements that are
 * part of the upper half. Each half is pre-sorted before being pushed where the
 * lower quarter ends above the upper quarter on stack B.
 * 
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param lis Struct that contains the Longest Increasing Subsequence and its
 * parameters.
 */
void	leave_lis_and_push_rest(t_stack *stack_a, t_stack *stack_b, t_lis lis)
{
	int	*remaining;
	int	remaining_size;

	remaining = get_remaining_elements(stack_a, lis);
	remaining_size = stack_a->top - lis.size + 1;
	find_quarters(stack_a, remaining, remaining_size);
	push_lower_half_and_pre_sort(stack_a, stack_b, lis);
	push_rest_and_pre_sort(stack_a, stack_b, lis);
	free(lis.sequence);
}

/**
 * @brief Returns an array with the elements that are not part of the Longest
 * Increasing Subsequence.
 * 
 * @param stack Pointer to stack A.
 * @param lis Struct that contains the Longest Increasing Subsequence and its
 * parameters.
 * @return int* Array with the remaining elements.
 */
int	*get_remaining_elements(t_stack *stack, t_lis lis)
{
	int	*remaining;
	int	i;
	int	j;

	remaining = malloc(sizeof(int) * (stack->top - lis.size + 1));
	if (!remaining)
		exit(ft_fprintf(STDERR_FILENO, "Malloc failed\n"));
	j = 0;
	i = stack->top;
	while (i >= 0)
	{
		if (!part_of_lis(stack->items[i], lis))
		{
			remaining[j] = stack->items[i].value;
			j++;
		}
		i--;
	}
	return (remaining);
}

/**
 * @brief Sorts the remaining elements and finds the values that divide the
 * array in four quarters.
 * 
 * @param stack Pointer to stack A.
 * @param remaining Array with the remaining elements.
 * @param size Size of the remaining array.
 */
void	find_quarters(t_stack *stack, int *remaining, int remaining_size)
{
	selection_sort(remaining, remaining_size);
	stack->quarters[0] = remaining[(remaining_size * 1 / 4)];
	stack->quarters[1] = remaining[(remaining_size * 2 / 4)];
	stack->quarters[2] = remaining[(remaining_size * 3 / 4)];
	free(remaining);
}

/**
 * @brief Pushes the elements that are part of the lower half of the remaining
 * elements to stack B and pre-sorts them where the lower quarter ends above
 * the upper quarter on stack B.
 * 
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param lis Struct that contains the Longest Increasing Subsequence and its
 * parameters.
 */
void	push_lower_half_and_pre_sort(t_stack *stack_a, t_stack *stack_b,
			t_lis lis)
{
	int	i;
	int	max_size;

	i = 0;
	max_size = stack_a->top + 1;
	while (i < max_size)
	{
		if (part_of_lis(stack_a->items[stack_a->top], lis))
			ra(stack_a, PUSH_SWAP);
		else
		{
			if (stack_a->items[stack_a->top].value <= stack_a->quarters[0])
				pb(stack_a, stack_b, PUSH_SWAP);
			else if (stack_a->items[stack_a->top].value <= stack_a->quarters[1])
			{
				pb(stack_a, stack_b, PUSH_SWAP);
				rb(stack_b, PUSH_SWAP);
			}
			else
				ra(stack_a, PUSH_SWAP);
		}
		i++;
	}
}

/**
 * @brief Pushes the elements that are part of the upper half of the remaining
 * elements to stack B and pre-sorts them where the lower quarter ends above
 * the upper quarter on stack B.
 * 
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param lis Struct that contains the Longest Increasing Subsequence and its
 * parameters.
 */
void	push_rest_and_pre_sort(t_stack *stack_a, t_stack *stack_b, t_lis lis)
{
	int	i;
	int	max_size;

	i = 0;
	max_size = stack_a->top + 1;
	while (i < max_size)
	{
		if (part_of_lis(stack_a->items[stack_a->top], lis))
			ra(stack_a, PUSH_SWAP);
		else
		{
			if (stack_a->items[stack_a->top].value <= stack_a->quarters[2])
				pb(stack_a, stack_b, PUSH_SWAP);
			else
			{
				pb(stack_a, stack_b, PUSH_SWAP);
				rb(stack_b, PUSH_SWAP);
			}
		}
		i++;
	}
}
