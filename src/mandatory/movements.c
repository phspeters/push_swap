/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:13:52 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/11 18:14:40 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **head, t_movement_node *move_list)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	if (first->next != NULL)
		first->next->prev = first;
	*head = second;
	//add_move(move_list, sa)
}

void	push(t_stack_node **head_a, t_stack_node **head_b)
{
	t_stack_node	*pushed_element;

	if (head_a == NULL || head_b == NULL)
		return ;
	pushed_element = *head_b;
	pushed_element->next = *head_a;
//	if ((*head_a)->prev != NULL)
//	{
//      (*head_a)->prev->next = pushed_element;
//  }
	(*head_a)->prev = pushed_element;
	(*head_b)->next->prev = NULL;
	*head_b = (*head_b)->next;
	*head_a = pushed_element;
}

void	rotate(t_stack_node **head)
{
	t_stack_node	*last;
	t_stack_node	*first;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = *head;
	first = (*head)->next;
	while (last->next != NULL)
		last = last->next;
	last->next = *head;
	(*head)->prev = last;
	first->prev = NULL;
	*head = first;
}

void	reverse_rotate(t_stack_node **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return ;
}

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
	The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
	The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one.
rrr : rra and rrb at the same time.*/