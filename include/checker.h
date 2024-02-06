/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:32:10 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/06 17:47:38 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stack.h"

//main.c

void	read_and_apply_instructions(t_stack *stack_a, t_stack *stack_b);
void	apply_instructions(char *instruction, t_stack *stack_a,
			t_stack *stack_b);

#endif