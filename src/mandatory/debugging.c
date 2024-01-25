/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:59:34 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/25 13:49:32 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arguments(t_arguments arguments)
{
	int			i;

	i = 0;
	while (i < arguments.size)
	{
		ft_printf("arg %i: %i\n", i, arguments.numbers[i]);
		i++;
	}
}

void	print_stack_value(t_stack stack, t_arguments s_arguments)
{
	int	i;

	i = 0;
	while (i < s_arguments.size)
	{
		printf("item %i: value = %i\n", i, stack.items[i].value);
		i++;
	}
}

void	print_stack_items(t_stack stack)
{
	int	i;

	i = 0;
	ft_printf("\n");
	while (i <= stack.top)
	{
		ft_printf("value = %i\tposition = %i\n", \
			stack.items[i].value, stack.items[i].arr_index);
		i++;
	}
	ft_printf("\n");
}
