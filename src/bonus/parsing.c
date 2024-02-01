/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:05:14 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/01 20:43:21 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_arguments	parse_arguments(int argc, char **argv)
{
	t_arguments	arguments;

	if (argc == 1)
		exit(EXIT_FAILURE);
	else if (argc == 2)
		arguments = parse_single_argument(argv[1]);
	else if (argc > 2)
		arguments = parse_multiple_arguments(argv + 1);
	if (!arguments.numbers)
		exit(ft_fprintf(STDERR_FILENO, "Error\n"));
	return (arguments);
}

t_arguments	parse_single_argument(char *arg_sentence)
{
	char		**splitted;
	t_arguments	arguments;

	splitted = ft_split(arg_sentence, ' ');
	if (!splitted)
		exit(ft_fprintf(STDERR_FILENO, "Malloc failed\n"));
	arguments = parse_multiple_arguments(splitted);
	ft_free_str_array(splitted);
	return (arguments);
}

t_arguments	parse_multiple_arguments(char **list)
{
	t_arguments	arguments;
	int			i;

	arguments.size = count_args(list);
	arguments.numbers = malloc(sizeof(long) * arguments.size);
	if (!arguments.numbers)
		exit(ft_fprintf(STDERR_FILENO, "Malloc failed\n"));
	i = 0;
	while (i < arguments.size)
	{
		arguments.numbers[i] = ft_atol(list[i]);
		if ((arguments.numbers[i] == 0) && (*list[i] != '0'))
		{
			arguments.numbers = NULL;
			break ;
		}
		i++;
	}
	if (check_for_duplicates_and_int_range(arguments.numbers, i))
	{
		free(arguments.numbers);
		arguments.numbers = NULL;
	}
	return (arguments);
}

int	count_args(char **list)
{
	int	arg_counter;

	arg_counter = 0;
	while (list[arg_counter])
		arg_counter++;
	return (arg_counter);
}

int	check_for_duplicates_and_int_range(long *numbers, int size)
{
	int	i;
	int	j;

	if (numbers == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		if ((numbers[i] > INT_MAX) || (numbers[i] < INT_MIN))
			return (EXIT_FAILURE);
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
