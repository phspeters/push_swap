/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:14:05 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/06 15:51:20 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Initializes the stacks parameters and allocates memory based on 
 * number of arguments.
 * 
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param arguments The arguments given to the program.
 */
void	initialize_stacks(t_stack *stack_a, t_stack *stack_b,
		t_arguments arguments)
{
	stack_a->items = malloc(sizeof(t_item) * arguments.size);
	if (!stack_a->items)
		exit(ft_fprintf(STDERR_FILENO, "Malloc failed\n"));
	stack_a->top = -1;
	stack_b->items = malloc(sizeof(t_item) * arguments.size);
	if (!stack_b->items)
		exit(ft_fprintf(STDERR_FILENO, "Malloc failed\n"));
	stack_b->top = -1;
}

/**
 * @brief Populates the stack items' value and arr_index with the given
 * arguments.
 * 
 * @param stack Pointer to the stack to be populated.
 * @param arguments The arguments given to the program.
 */
void	populate_stack(t_stack *stack, t_arguments arguments)
{
	int	i;
	int	size;

	size = arguments.size;
	i = 0;
	while (i < size)
	{
		stack->items[i].value = arguments.numbers[size - 1 - i];
		stack->items[i].arr_index = i;
		i++;
	}
	stack->top = i - 1;
	stack->max_size = i;
}

/**
 * @brief Updates the stack items values to their respective ranks in
 * ascending order. Begins at 0 for the smallest number.
 * 
 * @param stack Pointer to the stack to be ranked and updated.
 * @param arguments The arguments given to the program.
 */
void	rank_and_update_stack_values(t_stack *stack, t_arguments arguments)
{
	t_item	smallest_item;
	long	previous_smallest;
	int		rank;
	int		i;

	smallest_item.value = INT_MAX;
	previous_smallest = LONG_MIN;
	rank = -1;
	i = -1;
	while (++i <= stack->top)
	{
		if (arguments.numbers[i] <= smallest_item.value
			&& arguments.numbers[i] > previous_smallest)
		{
			smallest_item.arr_index = i;
			smallest_item.value = arguments.numbers[i];
		}
		if (i == stack->top && ++rank <= stack->top)
		{
			stack->items[stack->top - smallest_item.arr_index].value = rank;
			previous_smallest = smallest_item.value;
			smallest_item.value = INT_MAX;
			i = -1;
		}
	}
}

/**
 * @brief Checks if the stack is sorted in ascending order from top to bottom.
 * 
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 * @return 1 if the stack is sorted, 0 otherwise.
 */
int	sorted(t_stack stack_a, t_stack stack_b)
{
	int	i;

	if (stack_b.top != -1)
		return (0);
	i = 0;
	while (i < stack_a.top)
	{
		if (stack_a.items[i].value < stack_a.items[i + 1].value)
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Updates the arr_index of each item in the stack to match their
 * position in the array.
 * 
 * @param stack Pointer to the stack to have its items arr_index updated.
 */
void	calculate_stack_positions(t_stack *stack)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		stack->items[i].arr_index = i;
		i++;
	}
}
