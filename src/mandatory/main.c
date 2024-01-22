/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:16:48 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/22 18:39:32 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arguments(t_arguments arguments)
{
	int			i;

	i = 0;
	while (i < arguments.list_size)
	{
		ft_printf("arg %i: %i\n", i, arguments.numbers_list[i]);
		i++;
	}
}

void	print_stack_value(t_stack stack, t_arguments s_arguments)
{
	int	i;

	i = 0;
	while (i < s_arguments.list_size)
	{
		printf("element %i: value = %i\n", i, stack.list[i].value);
		i++;
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
		stack->top++;
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_arguments	arguments;
	t_stack		stack_a;
	t_stack		stack_b;

	arguments = parse_arguments(argc, argv);
	initialize_stacks(&stack_a, &stack_b, arguments);
	create_stack(&stack_a, arguments);
	//rotate(&stack_a);
	//reverse_rotate(&stack_a);
	//swap(&stack_a);
	//print_stack_value(stack_a, arguments);
	free(stack_a.list);
	free(stack_b.list);
	free(arguments.numbers_list);
	return (0);
}
