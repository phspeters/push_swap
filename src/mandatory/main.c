/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:16:48 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/16 16:29:04 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->head = NULL;
	stack_a->tail = NULL;
	stack_a->stack_size = 0;
	stack_b->head = NULL;
	stack_b->tail = NULL;
	stack_b->stack_size = 0;
}

int	main(int argc, char *argv[])
{
	t_stack			stack_a;
	t_stack			stack_b;
	//t_stack_node	*current;
	//int				i;

	initialize_stacks(&stack_a, &stack_b);
	parse_arguments(argc, argv);
	/*
	i = 0;
	while (i < 10)
	{
		create_node_and_append(&stack_a, i);
		//printf("head: %p\n", stack_a.head);
		//printf("tail: %p\n", stack_a.tail);
		//printf("size: %d\n", stack_a.stack_size);
		i++;
	}
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	rotate(&stack_b);
	swap(&stack_b);
	reverse_rotate(&stack_a);
	push(&stack_a, &stack_b);
	rotate(&stack_a);
	push(&stack_a, &stack_b);
	current = stack_a.head;
	while (current != NULL)
	{
		printf("stack_a: %i\n", current->number);
		current = current->next;
	}
	printf("\n");
	current = stack_b.head;
	while (current != NULL)
	{
		//printf("current: %p\n", current);
		printf("stack_b: %i\n", current->number);
		current = current->next;
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	*/
	return (0);
}
