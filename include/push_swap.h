/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:13:11 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/22 17:40:18 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_element
{
	int	value;
	int	stack_a_movement_cost;
	int	stack_b_movement_cost;
}	t_stack_element;

typedef struct s_stack
{
	int				top;
	t_stack_element	*list;
}	t_stack;

typedef struct s_arguments
{
	int		list_size;
	long	*numbers_list;
}	t_arguments;

//parsing.c
t_arguments	parse_arguments(int argc, char **argv);
t_arguments	parse_single_argument(char *argv);
t_arguments	parse_multiple_arguments(char **arguments);
int			check_for_duplicates_and_int_range(long *list, int size);
int			count_args(char **list);
//utils.c
long		ft_atol(const char *nptr);
//movements.c
void		swap(t_stack *stack);
void		push(t_stack *stack_a, t_stack *stack_b);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);

#endif
