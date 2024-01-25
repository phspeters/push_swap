/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:16:48 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/25 13:49:36 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank_and_update_stack(t_stack *stack, t_arguments arguments)
{
	t_item	smallest;
	int		previous_smallest;
	int		rank;
	int		i;

	smallest.value = INT_MAX;
	previous_smallest = INT_MIN;
	rank = -1;
	i = -1;
	while (++i <= stack->top)
	{
		if (arguments.numbers[i] < smallest.value
			&& arguments.numbers[i] > previous_smallest)
		{
			smallest.arr_index = i;
			smallest.value = arguments.numbers[i];
		}
		if (i == stack->top && ++rank <= stack->top)
		{
			stack->items[stack->top - smallest.arr_index].value = rank;
			previous_smallest = smallest.value;
			smallest.value = INT_MAX;
			i = -1;
		}
	}
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

void	create_stack(t_stack *stack, t_arguments arguments)
{
	int	i;
	int	size;

	size = arguments.size;
	i = 0;
	while (i < size)
	{
		stack->items[i].value = arguments.numbers[size - 1 - i];
		stack->items[i].arr_index = i;
		stack->top++;
		i++;
	}
	return ;
}

int	sorted(t_stack stack_a, t_stack stack_b)
{
	int	i;

	if (stack_b.top != -1)
		return (0);
	i = 0;
	while (i <= stack_a.top)
	{
		if (stack_a.items[i].value != \
		(stack_a.top - stack_a.items[i].arr_index))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_arguments	arguments;
	t_stack		stack_a;
	t_stack		stack_b;

	arguments = parse_arguments(argc, argv);
	initialize_stacks(&stack_a, &stack_b, arguments);
	create_stack(&stack_a, arguments);
	rank_and_update_stack(&stack_a, arguments);
	if (!sorted(stack_a, stack_b))
		sort(&stack_a, &stack_b);
	print_stack_items(stack_a);
	free_data(&stack_a, &stack_b, &arguments);
	return (0);
}
