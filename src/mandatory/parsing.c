/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:05:14 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/22 17:34:18 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_duplicates_and_int_range(long *list, int size)
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

t_arguments	parse_multiple_arguments(char **list)
{
	t_arguments	arguments;
	int			i;

	arguments.list_size = count_args(list);
	arguments.numbers_list = malloc(sizeof(long) * arguments.list_size);
	i = 0;
	while (i < arguments.list_size)
	{
		arguments.numbers_list[i] = ft_atol(list[i]);
		if ((arguments.numbers_list[i] == 0) && (*list[i] != '0'))
		{
			arguments.numbers_list = NULL;
			break ;
		}
		i++;
	}
	if (check_for_duplicates_and_int_range(arguments.numbers_list, i))
	{
		free(arguments.numbers_list);
		arguments.numbers_list = NULL;
	}
	return (arguments);
}

t_arguments	parse_single_argument(char *arg_sentence)
{
	char		**splitted;
	t_arguments	arguments;

	splitted = ft_split(arg_sentence, ' ');
	arguments = parse_multiple_arguments(splitted);
	ft_free_str_array(splitted);
	return (arguments);
}

t_arguments	parse_arguments(int argc, char **argv)
{
	t_arguments	arguments;

	if (argc == 1)
		exit(EXIT_FAILURE);
	else if (argc == 2)
		arguments = parse_single_argument(argv[1]);
	else if (argc > 2)
		arguments = parse_multiple_arguments(argv + 1);
	if (!arguments.numbers_list)
	{
		write(STDERR_FILENO, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	return (arguments);
}
