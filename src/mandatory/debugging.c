/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:59:34 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/23 14:52:25 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arguments(t_arguments arguments)
{
	int			i;

	i = 0;
	while (i < arguments.list_size)
	{
		ft_printf("arg %i: %i\n", i, arguments.numbers_list[i]);
		i++;
	}
}

void	print_stack_value(t_stack stack, t_arguments s_arguments)
{
	int	i;

	i = 0;
	while (i < s_arguments.list_size)
	{
		printf("element %i: value = %i\n", i, stack.list[i].value);
		i++;
	}
}

void	print_stack_elements(t_stack stack)
{
	int	i;

	i = 0;
	while (i <= stack.top)
	{
		ft_printf("value = %i\tposition = %i\n", \
			stack.list[i].value, stack.list[i].position);
		i++;
	}
	ft_printf("\n");
}
