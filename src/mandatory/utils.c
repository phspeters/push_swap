/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:54:45 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/18 13:41:05 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last(t_stack *stack)
{
	t_stack_node	*last_elem;

	if (stack->head == NULL)
		return (NULL);
	last_elem = stack->head;
	while (last_elem->next != NULL)
		last_elem = last_elem->next;
	return (last_elem);
}

void	create_node_and_append(t_stack *stack, int number)
{
	t_stack_node	*new_node;

	new_node = ft_calloc(sizeof(t_stack_node), 1);
	new_node->number = number;
	stack->stack_size++;
	if (stack->head == NULL)
	{
		stack->head = new_node;
		stack->tail = new_node;
		return ;
	}
	stack->tail->next = new_node;
	new_node->prev = stack->tail;
	stack->tail = new_node;
}

void	free_stack(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*next;

	current = stack->head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

long	ft_atol(const char *nptr)
{
	int		i;
	int		s;
	long	result;

	s = 1;
	i = 0;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		result = (nptr[i] - '0') + (result * 10);
		i++;
	}
	if (nptr[i] != '\0')
		return (0);
	return (result * s);
}
