/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:04:22 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/01 04:52:06 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (stack_a->size <= 1 || is_sorted(stack_a, stack_a->size))
	{
		free_stack(stack_a);
		return (0);
	}
	stack_b = create_empty_stack();
	if (!stack_b)
		free_stack_with_print_error(stack_a);
	sort(stack_a, stack_b);
	print_stacks_final(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q push_swap");
// }
