/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:30:58 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/01 20:43:19 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_arguments	arguments;
	t_stack		stack_a;
	t_stack		stack_b;

	arguments = parse_arguments(argc, argv);
	initialize_stacks(&stack_a, &stack_b, arguments);
	populate_stack(&stack_a, arguments);
	read_and_apply_instructions(&stack_a, &stack_b);
	if (sorted(stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_data(&stack_a, &stack_b, &arguments);
	return (0);
}

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
