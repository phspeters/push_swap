/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:16:48 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/07 14:01:58 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Main function of the push_swap program. It parses the arguments,
 * initializes the stacks, populates stack A, ranks and updates the stack
 * values, sorts the stack while printing the instructions and frees the 
 * allocated memory.
 * 
 * @param argc Number of arguments passed to the program.
 * @param argv Array of arguments passed to the program, as strings.
 * @return int EXIT_SUCCESS if the program runs successfully. 
 */
int	main(int argc, char **argv)
{
	t_arguments	arguments;
	t_stack		stack_a;
	t_stack		stack_b;

	arguments = parse_arguments(argc, argv);
	initialize_stacks(&stack_a, &stack_b, arguments);
	populate_stack(&stack_a, arguments);
	rank_and_update_stack_values(&stack_a, arguments);
	if (!sorted(stack_a, stack_b))
		sort(&stack_a, &stack_b);
	free_data(&stack_a, &stack_b, &arguments);
	return (EXIT_SUCCESS);
}
