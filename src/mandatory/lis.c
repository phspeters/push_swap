/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:53:22 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/26 19:38:39 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_lis_numbers(t_item *sequence, int *index_of_previous_element, int highest_element_index, int lis_size)
{
	int	*lis;
	int	i;
	int	j;

	lis = malloc(sizeof(int) * lis_size);
	j = highest_element_index;
	i = lis_size - 1;
	while (i >= 0)
	{
		lis[i] = sequence[j].value;
		j = index_of_previous_element[j];
		i--;
	}
	return (lis);
}

t_lis	get_lis(t_stack *stack)
{
	t_lis	lis;
	int		i;
	int		j;

	lis.size_ending_in_original_index = malloc(sizeof(int) * stack->top);
	lis.original_index_of_previous_element = malloc(sizeof(int) * stack->top);
	lis.highest_element_original_index = 0;
	lis.size = 0;
	i = -1;
	while (++i <= stack->top)
	{
		lis.size_ending_in_original_index[i] = 1;
		lis.original_index_of_previous_element[i] = -1;
	}
	i = stack->top - 1;
	while (i >= 0)
	{
		j = stack->top;
		while (j > i)
		{
			if ((stack->items[i].value > stack->items[j].value) && (lis.size_ending_in_original_index[i] <= lis.size_ending_in_original_index[j] + 1))
			{
				lis.size_ending_in_original_index[i] = lis.size_ending_in_original_index[j] + 1;
				lis.original_index_of_previous_element[i] = j;
				if (lis.size_ending_in_original_index[i] >= lis.size)
				{
					lis.size = lis.size_ending_in_original_index[i];
					lis.highest_element_original_index = i;
				}
			}
			j--;
		}
		i--;
	}
	if (lis.size < 3)
		lis.sequence = NULL;
	else
		lis.sequence = get_lis_numbers(stack->items, lis.original_index_of_previous_element, lis.highest_element_original_index, lis.size);
	free(lis.size_ending_in_original_index);
	free(lis.original_index_of_previous_element);
	return (lis);
}
