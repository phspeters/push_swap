/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:13:52 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/15 18:11:21 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_stack_node	*head;
	t_stack_node	*first;
	t_stack_node	*second;

	head = stack->head;
	if (head == NULL || head->next == NULL)
		return ;
	first = head;
	second = head->next;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	if (first->next != NULL)
		first->next->prev = first;
	head = second;
}

void	push(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*head_a;
	t_stack_node	*head_b;
	t_stack_node	*pushed_element;

	head_a = stack_a->head;
	head_b = stack_b->head;
	if (head_a == NULL || head_b == NULL)
		return ;
	pushed_element = head_b;
	pushed_element->next = head_a;
	head_a->prev = pushed_element;
	head_b->next->prev = NULL;
	head_b = head_b->next;
	head_a = pushed_element;
}

void	rotate(t_stack *stack)
{
	t_stack_node	*head;
	t_stack_node	*last;
	t_stack_node	*first;

	head = stack->head;
	if (head == NULL || head->next == NULL)
		return ;
	last = stack->tail;
	first = head->next;
	last->next = head;
	head->prev = last;
	first->prev = NULL;
	head = first;
}

void	reverse_rotate(t_stack *stack)
{
	t_stack_node	*head;
	t_stack_node	*last;

	head = stack->head;
	if (head == NULL || head->next == NULL)
		return ;
	last = stack->tail;
	last->prev->next = NULL;
	last->next = head;
	last->next->prev = last->next;
	last->prev = NULL;
	head = last;
}
