/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:54:45 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/02 19:39:40 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	has_invalid_chars(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '\0')
		return (1);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && !ft_isspace(arg[i]))
		{
			if ((arg[i] == '-' || arg[i] == '+') && ft_isdigit(arg[i + 1]))
				i++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	has_invalid_args(char **arg_list)
{
	int	i;

	i = 0;
	while (arg_list[i])
	{
		if (has_invalid_chars(arg_list[i]))
			return (1);
		i++;
	}
	return (0);
}

void	free_data(t_stack *stack_a, t_stack *stack_b, t_arguments *arguments)
{
	free(stack_a->items);
	free(stack_b->items);
	free(arguments->numbers);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
