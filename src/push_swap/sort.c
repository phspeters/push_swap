/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:00:58 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/06 17:24:18 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts the stack_a using the push_swap algorithm. It first gets the
 * longest increasing subsequence of the stack, then pushes the rest of the
 * stack to stack_b. After that, it calculates the costs of the cheapest item
 * in stack_b to be moved back to stack_a in it's proper position, and makes
 * the moves until the stack_a is sorted and stack_b is empty.
 * 
 * @param stack_a Stack to be sorted.
 * @param stack_b Auxiliary stack.
 */
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_lis	lis;
	t_item	cheapest;

	lis = get_lis(stack_a);
	if (lis.sequence)
		leave_lis_and_push_rest(stack_a, stack_b, lis);
	else
	{
		while (stack_a->top > 2)
			pb(stack_a, stack_b, PUSH_SWAP);
		sort_three_numbers(stack_a);
	}
	calculate_stack_positions(stack_b);
	while (!in_order(*stack_a, *stack_b))
	{
		cheapest = calculate_movement_costs(stack_a, stack_b);
		make_cheapest_move(cheapest, stack_a, stack_b);
	}
	if (!sorted(*stack_a, *stack_b))
		rotate_until_sorted(stack_a);
}

/**
 * @brief Sorts a stack with three numbers. As there are only six possible
 * combinations of the three numbers, the algorithm can sort the stack with a
 * maximum of two moves.
 * 
 * @param stack Stack containing 3 elements to be sorted.
 */
void	sort_three_numbers(t_stack *stack)
{
	int	highest;
	int	i;

	highest = -1;
	i = 0;
	while (i <= stack->top)
	{
		if (stack->items[i].value > highest)
			highest = stack->items[i].value;
		i++;
	}
	if (highest == stack->items[stack->top].value)
		ra(stack, PUSH_SWAP);
	else if (highest == stack->items[stack->top - 1].value)
		rra(stack, PUSH_SWAP);
	if (stack->items[stack->top].value > stack->items[stack->top - 1].value)
		sa(stack, PUSH_SWAP);
}

/**
 * @brief Checks if all the elements in the stack are in the right order.
 * That is, we only need to rotate or reverse rotate the stack for it to
 * be sorted.
 * It iterates through the stack, checking if the value of the current
 * element plus one equals the value of the next element, while using the
 * modulo operator to cycle back to the first element when the last element
 * is reached.
 * 
 * @param stack_a Stack to be checked.
 * @param stack_b Auxiliary stack.
 * @return int 1 if the stack is in order, 0 otherwise.
 */
int	in_order(t_stack stack_a, t_stack stack_b)
{
	int	i;

	if (stack_b.top >= 0)
		return (0);
	i = stack_a.top;
	while (i > 0)
	{
		if (((stack_a.items[i].value + 1) % (stack_a.top + 1))
			!= (stack_a.items[i - 1].value))
			return (0);
		i--;
	}
	return (1);
}

/**
 * @brief Rotates the stack until the first element is in the right position.
 * 
 * @param stack_a Stack to be rotated.
 */
void	rotate_until_sorted(t_stack *stack_a)
{
	int	i;
	int	middle;

	middle = stack_a->top / 2;
	i = stack_a->top;
	while (i >= 0)
	{
		if (stack_a->items[i].value == 0)
			break ;
		i--;
	}
	if (stack_a->items[i].arr_index >= middle)
	{
		while (stack_a->items[i].value
			!= stack_a->top - stack_a->items[i].arr_index)
			ra(stack_a, PUSH_SWAP);
	}
	else
	{
		while (stack_a->items[i].value
			!= stack_a->top - stack_a->items[i].arr_index)
			rra(stack_a, PUSH_SWAP);
	}
}

/**
 * @brief Performs a selection sort on the given array.
 * 
 * @param arr Integer array to be sorted. 
 * @param size Size of the array.
 */
void	selection_sort(int *arr, int size)
{
	int	smallest_index;
	int	swap;
	int	i;
	int	j;

	smallest_index = 0;
	i = 0;
	while (i < size)
	{
		j = i;
		smallest_index = i;
		while (j < size)
		{
			if (arr[j] < arr[smallest_index])
				smallest_index = j;
			j++;
		}
		swap = arr[i];
		arr[i] = arr[smallest_index];
		arr[smallest_index] = swap;
		i++;
	}
}
