/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:05:14 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/16 17:50:04 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_invalid_arguments(char **list)
{
	check_for_invalid_chars(list);
	//check_for_duplicates(list);
	return (0);
}

int	check_for_invalid_chars(char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		j = 0;
		while (list[j])
		{
			if (list[i][j] == '-')
			{
				if (!ft_isdigit(list[i][j + 1]))
					return (1);
			}
			else if (!ft_isdigit(list[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_arguments(int argc, char *argv[])
{
	char	**number_list;
	int		exit_status;

	exit_status = 1;
	number_list = NULL;
	if (argc == 1)
		exit(exit_status);
	else if (argc == 2)
		number_list = ft_split(argv[1], ' ');
	else if (argc > 2)
		number_list = ++argv;
	if (!check_for_invalid_arguments(number_list))
		exit_status = 0;
	while (**number_list)
		printf("%")
	//if (argc == 2)
	//	free_splitted(number_list);
	return (exit_status);
}
