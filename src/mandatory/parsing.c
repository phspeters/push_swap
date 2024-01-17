/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:05:14 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/17 20:43:26 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_duplicates_and_range(long *list, int size)
{
	int	i;
	int	j;

	if (list == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		if ((list[i] > INT_MAX) || (list[i] < INT_MIN))
			return (EXIT_FAILURE);
		j = i + 1;
		while (j < size)
		{
			if (list[i] == list[j])
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	free(list);
	return (EXIT_SUCCESS);
}

int	count_args(char **list)
{
	int	arg_counter;

	arg_counter = 0;
	while (list[arg_counter])
		arg_counter++;
	return (arg_counter);
}

int	parse_arguments_and_create_stack(char **list, t_stack *stack)
{
	int		arg_counter;
	long	*number_list;

	number_list = malloc(sizeof(int) * count_args(list));
	arg_counter = -1;
	while (list[++arg_counter])
	{
		number_list[arg_counter] = ft_atol(list[arg_counter]);
		if ((number_list[arg_counter] == 0) && (*list[arg_counter] != '0'))
		{
			free(number_list);
			number_list = NULL;
			break ;
		}
		create_node_and_append(stack, number_list[arg_counter]);
	}
	if (check_for_duplicates_and_range(number_list, arg_counter))
	{
		free(number_list);
		free_stack(stack);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parse_single_argument(char **arguments, t_stack *stack)
{
	int		exit_status;

	exit_status = parse_arguments_and_create_stack(arguments, stack);
	ft_free_str_array(arguments);
	return (exit_status);
}

void	create_stack(int argc, char *argv[], t_stack *stack)
{
	char	**arguments;
	int		exit_status;

	arguments = NULL;
	exit_status = EXIT_SUCCESS;
	if (argc == 1)
		exit(EXIT_FAILURE);
	else if (argc == 2)
	{
		arguments = ft_split(argv[1], ' ');
		exit_status = parse_single_argument(arguments, stack);
	}
	else if (argc > 2)
	{
		arguments = argv + 1;
		exit_status = parse_arguments_and_create_stack(arguments, stack);
	}
	if (exit_status == EXIT_FAILURE)
	{
		write(STDERR_FILENO, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
}
