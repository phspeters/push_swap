/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:05:14 by pehenri2          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/01/17 18:10:34 by pehenri2         ###   ########.fr       */
=======
/*   Updated: 2024/01/16 21:34:25 by pehenri2         ###   ########.fr       */
>>>>>>> 8c647c7e10c50a6e34d950c5abeaddf48aea6f5c
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

int	parse_arguments(char **list, int flag, t_stack *stack)
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
	if (flag == SINGLE_ARG)
		ft_free_str_array(list);
	if (check_for_duplicates_and_range(number_list, arg_counter))
	{
		free(number_list);
		free_stack(stack);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
//parse_single_argument
//parse_multiple_arguments
//both call parse_arguments but the first also frees 
void	create_stack(int argc, char *argv[], t_stack *stack)
{
<<<<<<< HEAD
	char	**arguments;
	int		*number_list;
	int		exit_status;

	arguments = NULL;
	number_list = NULL;
	exit_status = EXIT_SUCCESS;
=======
	char	**argument_list;
	char	**malloc;
	int		exit_status;

	exit_status = 1;
	argument_list = NULL;
	malloc = NULL;
>>>>>>> 8c647c7e10c50a6e34d950c5abeaddf48aea6f5c
	if (argc == 1)
		exit(EXIT_FAILURE);
	else if (argc == 2)
	{
<<<<<<< HEAD
		arguments = ft_split(argv[1], ' ');
		exit_status = parse_arguments(arguments, SINGLE_ARG, stack);
	}
	else if (argc > 2)
	{
		arguments = argv + 1;
		exit_status = parse_arguments(arguments, MULTI_ARG, stack);
	}
	if (exit_status == EXIT_FAILURE)
	{
		write(STDERR_FILENO, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
=======
		argument_list = ft_split(argv[1], ' ');
		malloc = argument_list;
	}
	else if (argc > 2)
		argument_list = ++argv;
	if (!check_for_invalid_arguments(argument_list))
		exit_status = 0;
	if (malloc)
		free_ptr_array(argument_list);
	return (exit_status);
>>>>>>> 8c647c7e10c50a6e34d950c5abeaddf48aea6f5c
}
