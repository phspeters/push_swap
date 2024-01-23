/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:13:11 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/23 18:17:13 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack_element
{
	int	value;
	int	position;
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
void		free_data(t_stack *stack_a, t_stack *stack_b,
				t_arguments *arguments);

//push.c
void		push(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);

//swap.c
void		swap(t_stack *stack);
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack_a, t_stack *stack_b);

//rotate.c
void		rotate(t_stack *stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack_a, t_stack *stack_b);

//reverse_rotate.c
void		reverse_rotate(t_stack *stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack_a, t_stack *stack_b);

//debugging.c
void		print_stack_value(t_stack stack, t_arguments s_arguments);
void		print_arguments(t_arguments arguments);
void		print_stack_elements(t_stack stack);

#endif
