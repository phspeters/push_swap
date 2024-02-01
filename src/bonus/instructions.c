/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:16:54 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/01 18:24:31 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_and_apply_instructions(t_stack *stack_a, t_stack *stack_b)
{
	char	buffer[4];
	int		i;

	i = 0;
	while (read(0, &buffer[i], 1) == 1)
	{
		if (buffer[i] == '\n')
		{
			apply_instructions(buffer, stack_a, stack_b);
			i = 0;
		}
		else
			i++;
	}
}

void	apply_instructions(char *instruction, t_stack *stack_a,
	t_stack *stack_b)
{
	if (ft_strncmp(instruction, "ra\n", 3))
		ra(stack_a);
	else if (ft_strncmp(instruction, "rb\n", 3))
		ra(stack_b);
	else if (ft_strncmp(instruction, "rr\n", 3))
		rr(stack_a, stack_b);
	else if (ft_strncmp(instruction, "rra\n", 4))
		rra(stack_a);
	else if (ft_strncmp(instruction, "rrb\n", 4))
		rrb(stack_b);
	else if (ft_strncmp(instruction, "rrr\n", 4))
		rrr(stack_a, stack_b);
	else if (ft_strncmp(instruction, "sa\n", 3))
		sa(stack_a);
	else if (ft_strncmp(instruction, "sb\n", 3))
		sb(stack_b);
	else if (ft_strncmp(instruction, "ss\n", 3))
		ss(stack_a, stack_b);
	else if (ft_strncmp(instruction, "pa\n", 3))
		pa(stack_a, stack_b);
	else if (ft_strncmp(instruction, "pb\n", 3))
		pb(stack_a, stack_b);
	else
		ft_printf("Error\n");
}
