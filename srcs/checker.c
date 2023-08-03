/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:32:34 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/03 23:51:52 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	main(int argc, const char **argv)
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;

	line = NULL;
	while (true)
	{
		line = get_next_line(0);
		printf("line: %s", line);
		if (!line)
		{
			printf("End of stdin\n");
			break ;
		}
		free(line);
		line = NULL;
	}
	if (argc == 1)
		return (0);
	if (!is_valid_arg(--argc, ++argv))
		exit_with_print_error();
	stack_a = parse_input(argc, argv);
	if (!stack_a)
		exit_with_print_error();
	if (stack_a->size <= 1 || is_sorted(stack_a, stack_a->size))
	{
		free_stack(stack_a);
		return (0);
	}
	stack_b = create_empty_stack();
	if (!stack_b)
		free_stack_with_print_error(stack_a);
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
