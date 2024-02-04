/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 09:46:37 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/04 09:50:18 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leave_lis_and_push_rest(t_stack *stack_a, t_stack *stack_b, t_lis lis)
{
	int	*remaining;
	int	remaining_size;

	remaining = get_remaining_elements(stack_a, lis);
	remaining_size = stack_a->top - lis.size + 1;
	find_quarters(stack_a, remaining, remaining_size);
	push_lower_half_and_pre_sort(stack_a, stack_b, lis);
	push_rest_and_pre_sort(stack_a, stack_b, lis);
	free(lis.sequence);
}

int	*get_remaining_elements(t_stack *stack, t_lis lis)
{
	int	*remaining;
	int	i;
	int	j;

	remaining = malloc(sizeof(int) * (stack->top - lis.size + 1));
	if (!remaining)
		exit(ft_fprintf(STDERR_FILENO, "Malloc failed\n"));
	j = 0;
	i = stack->top;
	while (i >= 0)
	{
		if (!part_of_lis(stack->items[i], lis))
		{
			remaining[j] = stack->items[i].value;
			j++;
		}
		i--;
	}
	return (remaining);
}

void	find_quarters(t_stack *stack, int *remaining, int size)
{
	selection_sort(remaining, size);
	stack->quarters[0] = remaining[(size * 1 / 4)];
	stack->quarters[1] = remaining[(size * 2 / 4)];
	stack->quarters[2] = remaining[(size * 3 / 4)];
	free(remaining);
}

void	push_lower_half_and_pre_sort(t_stack *stack_a, t_stack *stack_b,
			t_lis lis)
{
	int	i;
	int	max_size;

	i = 0;
	max_size = stack_a->top + 1;
	while (i < max_size)
	{
		if (part_of_lis(stack_a->items[stack_a->top], lis))
			ra(stack_a, PUSH_SWAP);
		else
		{
			if (stack_a->items[stack_a->top].value <= stack_a->quarters[0])
				pb(stack_a, stack_b, PUSH_SWAP);
			else if (stack_a->items[stack_a->top].value <= stack_a->quarters[1])
			{
				pb(stack_a, stack_b, PUSH_SWAP);
				rb(stack_b, PUSH_SWAP);
			}
			else
				ra(stack_a, PUSH_SWAP);
		}
		i++;
	}
}

void	push_rest_and_pre_sort(t_stack *stack_a, t_stack *stack_b, t_lis lis)
{
	int	i;
	int	max_size;

	i = 0;
	max_size = stack_a->top + 1;
	while (i < max_size)
	{
		if (part_of_lis(stack_a->items[stack_a->top], lis))
			ra(stack_a, PUSH_SWAP);
		else
		{
			if (stack_a->items[stack_a->top].value <= stack_a->quarters[2])
				pb(stack_a, stack_b, PUSH_SWAP);
			else
			{
				pb(stack_a, stack_b, PUSH_SWAP);
				rb(stack_b, PUSH_SWAP);
			}
		}
		i++;
	}
}
