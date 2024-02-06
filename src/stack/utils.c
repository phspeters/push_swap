/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:54:45 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/06 15:48:18 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Checks if the string has invalid characters. That is, if it has any
 * character that is not a digit, a space or a sign.
 * 
 * @param arg The string to be checked.
 * @return 1 if the string has invalid characters, 0 otherwise.
 */
int	has_invalid_chars(char *arg)
{
	int	i;
	int	has_digits;

	if (arg[0] == '\0')
		return (1);
	has_digits = 0;
	i = -1;
	while (arg[++i])
	{
		if ((ft_issign(arg[i]) && ft_isdigit(arg[i + 1])) || ft_isspace(arg[i]))
			continue ;
		else if (ft_isdigit(arg[i]))
		{
			has_digits = 1;
			if (ft_isspace(arg[i + 1]) || ft_isdigit(arg[i + 1]) || !arg[i + 1])
				continue ;
			else
				return (1);
		}
		else
			return (1);
	}
	if (!has_digits)
		return (1);
	return (0);
}

/**
 * @brief Checks if any argument inside the arg_list has invalid characters.
 * 
 * @param arg_list The list of arguments to be checked.
 * @return 1 if the arguments have invalid characters, 0 otherwise.
 */
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

/**
 * @brief Frees the memory allocated for the stacks and the arguments.
 * 
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param arguments Pointer to arguments struct.
 */
void	free_data(t_stack *stack_a, t_stack *stack_b, t_arguments *arguments)
{
	free(stack_a->items);
	free(stack_b->items);
	free(arguments->numbers);
}

/**
 * @brief Returns the maximum value between a and b.
 * 
 * @param a First value.
 * @param b Second value.
 * @return The maximum value between a and b.
 */
int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/**
 * @brief Returns the minimum value between a and b.
 * 
 * @param a First value.
 * @param b Second value.
 * @return The minimum value between a and b.
 */
int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
