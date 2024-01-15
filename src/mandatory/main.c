/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:16:48 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/15 18:11:41 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack			stack_a;
	t_stack_node	*head_a;
	t_stack_node	*current;
	int				i;

	stack_a.head = NULL;
	stack_a.tail = NULL;
	stack_a.stack_size = 0;
	head_a = stack_a.head;
	i = 0;
	while (i < 5)
	{
		create_node_and_append(&stack_a, i);
		i++;
	}
	current = head_a;
	while (current != NULL)
	{
		printf("number: %i\n", current->number);
		current = current->next;
	}
	current = find_last(&stack_a);
	while (current != NULL)
	{
		printf("number: %i\n", current->number);
		current = current->prev;
	}
	free_stack(&stack_a);
	return (0);
}
