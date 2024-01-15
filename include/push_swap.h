/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:13:11 by pehenri2          #+#    #+#             */
/*   Updated: 2024/01/15 18:08:50 by pehenri2         ###   ########.fr       */
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

typedef struct s_stack_node
{
	int					number;
	int					movement_cost;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_stack
{
	int					stack_size;
	struct s_stack_node	*head;
	struct s_stack_node	*tail;
}	t_stack;

typedef struct s_movement_node
{
	char					*move;
	struct s_movement_node	*next;
}	t_movement_node;
//utils.c
t_stack_node	*find_last(t_stack *stack);
void			create_node_and_append(t_stack *stack, int number);
void			free_stack(t_stack	*stack);
//movements.c
void			swap(t_stack *stack);
void			push(t_stack *stack_a, t_stack *stack_b);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);

#endif
