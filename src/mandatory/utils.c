/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:54:45 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/15 18:01:04 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last(t_stack *stack)
{
	t_stack_node	*head;
	t_stack_node	*last_elem;

	head = stack->head;
	if (head == NULL)
		return (NULL);
	last_elem = head;
	while (last_elem->next != NULL)
		last_elem = last_elem->next;
	return (last_elem);
}

void	create_node_and_append(t_stack *stack, int number)
{
	t_stack_node	*head;
	t_stack_node	*tail;
	t_stack_node	*new_node;

	head = stack->head;
	tail = stack->tail;
	new_node = ft_calloc(sizeof(t_stack_node), 1);
	new_node->number = number;
	if (head == NULL)
	{
		head = new_node;
		return ;
	}
	tail->next = new_node;
	new_node->prev = tail;
}

void	free_stack(t_stack	*stack)
{
	t_stack_node	*current;

	current = stack->head;
	while (current != NULL)
	{
		current = current->next;
		free(current->prev);
	}
	free(stack->tail);
}
