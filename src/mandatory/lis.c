/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:53:22 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/01 20:43:27 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lis	get_lis(t_stack *stack)
{
	t_lis	lis;
	int		i;
	int		j;

	initialize_lis_parameters(&lis, *stack);
	i = stack->top -1;
	while (i >= 0)
	{
		j = stack->top;
		while (--j > i)
		{
			if ((stack->items[i].value > stack->items[j].value)
				&& (lis.size_ending_in_original_index[i]
					<= lis.size_ending_in_original_index[j] + 1))
				update_lis_parameters(&lis, i, j);
			j--;
		}
		i--;
	}
	lis.sequence = get_lis_numbers(stack->items, &lis);
	return (lis);
}

void	initialize_lis_parameters(t_lis *lis, t_stack stack)
{
	int	i;

	lis->size_ending_in_original_index = malloc(sizeof(int) * (stack.max_size));
	lis->original_index_of_previous_element
		= malloc(sizeof(int) * (stack.max_size));
	if (!lis->size_ending_in_original_index
		|| !lis->original_index_of_previous_element)
		exit(ft_fprintf(STDERR_FILENO, "Malloc failed\n"));
	lis->highest_element_original_index = 0;
	lis->size = 0;
	i = -1;
	while (++i < stack.max_size)
	{
		lis->size_ending_in_original_index[i] = 1;
		lis->original_index_of_previous_element[i] = -1;
	}
}

void	update_lis_parameters(t_lis *lis, int i, int j)
{
	lis->size_ending_in_original_index[i]
		= lis->size_ending_in_original_index[j] + 1;
	lis->original_index_of_previous_element[i] = j;
	if (lis->size_ending_in_original_index[i] >= lis->size)
	{
		lis->size = lis->size_ending_in_original_index[i];
		lis->highest_element_original_index = i;
	}
}

int	*get_lis_numbers(t_item *items, t_lis *lis)
{
	int	*sequence;
	int	i;
	int	j;

	if (lis->size > 3)
	{
		sequence = malloc(sizeof(int) * lis->size);
		if (!sequence)
			exit(ft_fprintf(STDERR_FILENO, "Malloc failed\n"));
		j = lis->highest_element_original_index;
		i = lis->size - 1;
		while (i >= 0)
		{
			sequence[i] = items[j].value;
			j = lis->original_index_of_previous_element[j];
			i--;
		}
	}
	else
		sequence = NULL;
	free(lis->size_ending_in_original_index);
	free(lis->original_index_of_previous_element);
	return (sequence);
}

void	leave_lis_and_push_rest(t_stack *stack_a, t_stack *stack_b, t_lis lis)
{
	int	i;

	i = 0;
	while (i < lis.size)
	{
		if (stack_a->items[stack_a->top].value == lis.sequence[i])
		{
			ra(stack_a);
			i++;
		}
		else
			pb(stack_a, stack_b);
		if (i > lis.size - 1)
			while (stack_a->items[stack_a->top].value != lis.sequence[0])
				pb(stack_a, stack_b);
	}
	free(lis.sequence);
}
