/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:53:22 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/06 17:55:36 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculates the Longest Increasing Subsequence of a stack and it's size.
 * The Longest Increasing Subsequence is the longest sequence of numbers that
 * are in increasing order in the stack.
 * The function uses memoization to avoid repetition while calculating the LIS.
 * It uses a supporting array to store the size of the LIS ending in each index
 * of the stack.
 * 	e.g. Given two indexes i and j, where j is smaller than i. If at index i
 * the value is greater than the value at index j, than, the size of the LIS
 * ending in index i is the size of the LIS ending in index j, + 1.
 * The function also stores the index of the previous element of the LIS in
 * another supporting array, effectively serving as breadcrumbs to reconstruct
 * the LIS.
 * 
 * @param stack Pointer to the stack.
 * @return t_lis Struct that contains the Longest Increasing Subsequence and its
 * parameters.
 */
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
		while (j > i)
		{
			if ((stack->items[i].value > stack->items[j].value)
				&& (lis.size_ending_in_original_index[i]
					<= lis.size_ending_in_original_index[j]))
				update_lis_parameters(&lis, i, j);
			j--;
		}
		i--;
	}
	lis.sequence = get_lis_numbers(stack->items, &lis);
	return (lis);
}

/**
 * @brief Initializes the parameters of the Longest Increasing Subsequence
 * and allocates memory for the supporting arrays.
 * 
 * @param lis Pointer to the t_lis struct.
 * @param stack The stack.
 */
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

/**
 * @brief Updates the parameters of the supporting arrays of the Longest
 * Increasing Subsequence based on the indexes of the elements of the stack.
 * 
 * @param lis Pointer to the t_lis struct.
 * @param i Index of the element to be updated.
 * @param j Index of the previous element.
 */
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

/**
 * @brief Allocates memory for the Longest Increasing Subsequence and stores
 * the numbers of the LIS in an array using the supporting arrays as breadcrumbs.
 * 
 * @param items The items of the stack.
 * @param lis Pointer to the t_lis struct.
 * @return int* Pointer to the array of the numbers of the LIS.
 */
int	*get_lis_numbers(t_item *items, t_lis *lis)
{
	int	*sequence;
	int	i;
	int	j;

	if (lis->size > 4)
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

/**
 * @brief Checks if an item is part of the Longest Increasing Subsequence.
 * 
 * @param item The item to be checked.
 * @param lis The Longest Increasing Subsequence.
 * @return int 1 if the item is part of the LIS, 0 otherwise.
 */
int	part_of_lis(t_item item, t_lis lis)
{
	int	i;

	i = 0;
	while (i < lis.size)
	{
		if (item.value == lis.sequence[i])
			return (1);
		i++;
	}
	return (0);
}
