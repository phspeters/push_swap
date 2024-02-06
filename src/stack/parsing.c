/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:05:14 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/06 17:26:44 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Parses the arguments passed to the program and converts them to 
 * integers. Will ultimately check for invalid chars, duplicates and if the
 * numbers are within the integer range.
 * 
 * @param argc Number of arguments passed to the function.
 * @param argv An array of pointers to the strings which are those arguments. 
 *				The first argument, argv[0], is the name of the program itself.
 * @return t_arguments --- holds the size of the array and the array of
 * integers.
 */
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

/**
 * @brief Split the single string holding all the arguments into an array of
 * strings and calls parse_multiple_arguments.
 * 
 * @param arg_sentence Single string holding all the arguments.
 * @return t_arguments --- holds the size of the array and the array of
 * integers.
 */
t_arguments	parse_single_argument(char *arg_sentence)
{
	t_arguments	arguments;
	char		**splitted;

	splitted = ft_split(arg_sentence, ' ');
	if (!splitted)
		exit(ft_fprintf(STDERR_FILENO, "Malloc failed\n"));
	arguments = parse_multiple_arguments(splitted);
	ft_free_str_array(splitted);
	return (arguments);
}

/**
 * @brief Checks for invalid chars, duplicate values and if the numbers are
 * within integer range.
 * After everything is checked, converts the strings to integers and stores
 * them in an array.
 * 
 * @param arg_list Array of strings holding the arguments.
 * @return t_arguments --- holds the size of the array and the array of
 * integers.
 */
t_arguments	parse_multiple_arguments(char **arg_list)
{
	t_arguments	arguments;
	int			i;

	if (has_invalid_args(arg_list))
		exit(ft_fprintf(STDERR_FILENO, "Error\n"));
	arguments.size = count_args(arg_list);
	arguments.numbers = malloc(sizeof(long) * arguments.size);
	if (!arguments.numbers)
		exit(ft_fprintf(STDERR_FILENO, "Malloc failed\n"));
	i = -1;
	while (++i < arguments.size)
	{
		arguments.numbers[i] = ft_atol(arg_list[i]);
		if ((arguments.numbers[i] == 0) && (*arg_list[i] != '0'))
		{
			arguments.numbers = NULL;
			break ;
		}
	}
	if (check_for_duplicates_and_int_range(arguments.numbers, i))
	{
		free(arguments.numbers);
		arguments.numbers = NULL;
	}
	return (arguments);
}

/**
 * @brief Counts the number of arguments in the array of strings.
 * 
 * @param arg_list Array of strings holding the arguments.
 * @return Number of arguments as an int.
 */
int	count_args(char **arg_list)
{
	int	arg_counter;

	arg_counter = 0;
	while (arg_list[arg_counter])
		arg_counter++;
	return (arg_counter);
}

/**
 * @brief Checks for duplicate values and if the numbers are within
 * the integer range.
 * 
 * @param numbers Array of arguments as longs.
 * @param size Size of the array.
 * @return 0 if there are no duplicates and the numbers are within
 * the integer range. 1 otherwise. 
 */
int	check_for_duplicates_and_int_range(long *numbers, int size)
{
	int	i;
	int	j;

	if (numbers == NULL)
		return (1);
	i = 0;
	while (i < size)
	{
		if ((numbers[i] > INT_MAX) || (numbers[i] < INT_MIN))
			return (1);
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
