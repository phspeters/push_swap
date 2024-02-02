/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:14:05 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/02 17:23:47 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
