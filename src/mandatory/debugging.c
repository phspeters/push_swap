/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:59:34 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/27 18:39:13 by pehenri2         ###   ########.fr       */
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

void	print_item(t_item item)
{
	ft_printf("\n\tvalue: %i\n", item.value);
	ft_printf("\tarr_index: %i\n", item.arr_index);
	ft_printf("\tstack_a_movement_cost: %i\n", item.stack_a_movement_cost);
	ft_printf("\tstack_b_movement_cost: %i\n", item.stack_b_movement_cost);
	ft_printf("\tcombined_cost: %i\n\n", item.combined_cost);
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

void	print_lis(t_lis lis)
{
	int	i;

	if (!lis.sequence)
		return ;
	ft_printf("size: %i\n", lis.size);
	i = 0;
	while (i < lis.size)
	{
		ft_printf("\tlis[%i]: %i\n", i, lis.sequence[i]);
		i++;
	}
}

void	print_both_stacks(t_stack stack_a, t_stack stack_b)
{
	int	a;
	int	b;

	a = stack_a.top;
	b = stack_b.top;
	ft_printf("Stack A\t\t\t\t\tStack B\n");
	ft_printf("Top: %i\t\t\t\t\tTop: %i\n", stack_a.top, stack_b.top);
	while (a >= 0 && b >= 0)
	{
		ft_printf("value: %i\tarr_index: %i\t\tvalue: %i\tarr_index: %i\n", stack_a.items[a].value, stack_a.items[a].arr_index, stack_b.items[b].value, stack_b.items[b].arr_index);
		a--;
		b--;
	}
	while (a >= 0)
	{
		ft_printf("value: %i\tarr_index: %i\n", stack_a.items[a].value, stack_a.items[a].arr_index);
		a--;
	}
	while (b-- >= 0)
	{
		ft_printf("\t\t\t\t\tvalue: %i\tarr_index: %i\n", stack_b.items[b].value, stack_b.items[b].arr_index);
		b--;
	}
}
