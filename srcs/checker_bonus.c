/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:32:34 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 02:18:45 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static bool	is_valid_command(char *line)
{
	if (line)
		return (true);
	return (false);
}

static void	read_command_and_sort(t_stack *a, t_stack *b)
{
	char	*line;

	while (true)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		printf("line: %s", line);
		if (!is_valid_command(line))
		{
			free(line);
			free_stacks_with_print_error(a, b);
		}
		//execute_command(a, b, line);
		free(line);
		line = NULL;
	}
}

int	main(int argc, const char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	if (!is_valid_arg(--argc, ++argv))
		exit_with_print_error();
	stack_a = parse_input(argc, argv);
	if (!stack_a)
		exit_with_print_error();
	stack_b = create_empty_stack();
	if (!stack_b)
		free_stack_with_print_error(stack_a);
	read_command_and_sort(stack_a, stack_b);
	// if (is_sorted(stack_a) && stack_b->guard->next == stack_b->guard->prev)
	// 	ft_putendl_fd("OK", 1);
	// else
	// 	ft_putendl_fd("KO", 1);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
