/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:16:48 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/23 17:00:50 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank_and_update_stack(t_stack *stack, t_arguments arguments)
{
	t_stack_element	smallest;
	int				previous_smallest;
	int				rank;
	int				i;

	smallest.value = INT_MAX;
	previous_smallest = INT_MIN;
	rank = -1;
	i = -1;
	while (++i <= stack->top)
	{
		if (arguments.numbers_list[i] < smallest.value && \
		arguments.numbers_list[i] > previous_smallest)
		{
			smallest.position = i;
			smallest.value = arguments.numbers_list[i];
		}
		if (i == stack->top && ++rank <= stack->top)
		{
			stack->list[smallest.position].value = rank;
			previous_smallest = smallest.value;
			smallest.value = INT_MAX;
			i = -1;
		}
	}
}

void	initialize_stacks(t_stack *stack_a, t_stack *stack_b,
		t_arguments arguments)
{
	stack_a->list = malloc(sizeof(t_stack_element) * arguments.list_size);
	stack_a->top = -1;
	stack_b->list = malloc(sizeof(t_stack_element) * arguments.list_size);
	stack_b->top = -1;
}

void	create_stack(t_stack *stack, t_arguments arguments)
{
	int	i;

	i = 0;
	while (i < arguments.list_size)
	{
		stack->list[i].value = arguments.numbers_list[i];
		stack->list[i].position = i;
		stack->top++;
		i++;
	}
	return ;
}

int	is_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (i <= stack.top)
	{
		if (stack.list[i].value != stack.list[i].position)
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
	if (!is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	free_data(&stack_a, &stack_b, &arguments);
	return (0);
}
