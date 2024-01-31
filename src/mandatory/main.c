/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:16:48 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/31 18:48:26 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_arguments	arguments;
	t_stack		stack_a;
	t_stack		stack_b;

	arguments = parse_arguments(argc, argv);
	initialize_stacks(&stack_a, &stack_b, arguments);
	populate_stack(&stack_a, arguments);
	rank_and_update_stack_values(&stack_a, arguments);
	if (!sorted(stack_a, stack_b))
		sort(&stack_a, &stack_b);
	free_data(&stack_a, &stack_b, &arguments);
	return (0);
}

void	initialize_stacks(t_stack *stack_a, t_stack *stack_b,
		t_arguments arguments)
{
	stack_a->items = malloc(sizeof(t_item) * arguments.size);
	if (!stack_a->items)
		exit(ft_printf("Malloc failed\n"));
	stack_a->top = -1;
	stack_b->items = malloc(sizeof(t_item) * arguments.size);
	if (!stack_b->items)
		exit(ft_printf("Malloc failed\n"));
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
	int		previous_smallest;
	int		rank;
	int		i;

	smallest_item.value = INT_MAX;
	previous_smallest = INT_MIN;
	rank = -1;
	i = -1;
	while (++i <= stack->top)
	{
		if (arguments.numbers[i] < smallest_item.value
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
