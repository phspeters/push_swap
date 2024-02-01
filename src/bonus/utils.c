/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:54:45 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/01 13:57:34 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	free_data(t_stack *stack_a, t_stack *stack_b, t_arguments *arguments)
{
	free(stack_a->items);
	free(stack_b->items);
	free(arguments->numbers);
}

void	calculate_stack_positions(t_stack *stack)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		stack->items[i].arr_index = i;
		i++;
	}
}
