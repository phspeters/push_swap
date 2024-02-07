/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:30:58 by pehenri2          #+#    #+#             */
/*   Updated: 2024/02/07 14:10:41 by pehenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * @brief Main function of the checker program. It parses the arguments,
 * initializes the stacks, populates the stack A, reads and applies the
 * instructions and checks if the stack is sorted. Prints "OK" if it is, "KO"
 * otherwise. Because the program reads from the standard input, it will keep
 * reading until ctrl+D is pressed to send an EOF to the terminal, effectively
 * ending the read loop and finishing the program.
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
	read_and_apply_instructions(&stack_a, &stack_b);
	if (sorted(stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_data(&stack_a, &stack_b, &arguments);
	return (EXIT_SUCCESS);
}

/**
 * @brief Reads the instructions from the standard input and applies them to the
 * stacks. Each instruction is separated by a newline character.
 * 
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 */
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

/**
 * @brief Applies the instructions to the stacks. If the instruction is not
 * recognized, the program exits with an error message.
 * 
 * @param instruction The instruction to be applied.
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 */
void	apply_instructions(char *instruction, t_stack *stack_a,
	t_stack *stack_b)
{
	if (ft_strncmp(instruction, "ra\n", 3) == 0)
		ra(stack_a, CHECKER);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		ra(stack_b, CHECKER);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rr(stack_a, stack_b, CHECKER);
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		rra(stack_a, CHECKER);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		rrb(stack_b, CHECKER);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, CHECKER);
	else if (ft_strncmp(instruction, "sa\n", 3) == 0)
		sa(stack_a, CHECKER);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		sb(stack_b, CHECKER);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		ss(stack_a, stack_b, CHECKER);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		pa(stack_a, stack_b, CHECKER);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		pb(stack_a, stack_b, CHECKER);
	else
		exit(ft_fprintf(STDERR_FILENO, "Error\n"));
}
