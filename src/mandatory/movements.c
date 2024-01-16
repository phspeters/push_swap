/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:13:52 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/16 15:48:01 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	first = stack->head;
	second = stack->head->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	stack->head = second;
}

void	push(t_stack *origin_stack, t_stack *destination_stack)
{
	t_stack_node	*destination_head;
	t_stack_node	*origin_head;
	t_stack_node	*pushed_element;

	origin_head = origin_stack->head;
	if (origin_head == NULL)
		return ;
	origin_stack->head = origin_stack->head->next;
	destination_head = destination_stack->head;
	pushed_element = origin_head;
	pushed_element->next = destination_head;
	pushed_element->prev = NULL;
	if (destination_head)
		destination_head->prev = pushed_element;
	destination_stack->head = pushed_element;
	if (!destination_stack->tail)
		destination_stack->tail = pushed_element;
	origin_stack->stack_size--;
	destination_stack->stack_size++;
}

void	rotate(t_stack *stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	first = stack->head;
	if (first == NULL || first->next == NULL)
		return ;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	last = stack->tail;
	stack->tail = first;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	reverse_rotate(t_stack *stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	first = stack->head;
	if (first == NULL || first->next == NULL)
		return ;
	last = stack->tail;
	stack->head = last;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
}
