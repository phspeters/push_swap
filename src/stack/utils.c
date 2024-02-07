/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:54:45 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/07 16:54:32 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Checks if the string has invalid characters. That is, if it has any
 * character that is not a digit, except for the first character, which can be a
 * sign.
 * 
 * @param arg The string to be checked.
 * @return 1 if the string has invalid characters, 0 otherwise.
 */
int	has_invalid_chars(char *arg)
{
	int	i;

	if (*arg == '\0')
		return (1);
	i = -1;
	if ((ft_issign(arg[0]) && ft_isdigit(arg[1])))
		i++;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
	}
	return (0);
}

/**
 * @brief Checks if any argument inside the arg_list has invalid characters
 * by calling has_invalid_chars.
 * 
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
