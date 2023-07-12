/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:04:22 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/12 19:22:49 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_nord *guard_nord)
{
	t_nord	*node;

	if (!guard_nord)
		return ;
	node = guard_nord->next;
	while (node && node != guard_nord)
	{
		printf("%d ", node->value);
		node = node->next;
	}
}

int	main(int argc, const char **argv)
{
	t_stack	*stack_a;

	if (argc == 1 || !is_valid_arg(--argc, ++argv))
		exit_with_print_error();
	stack_a = parse_input(argc, argv);
	if (!stack_a)
		exit_with_print_error();
	print_stack(stack_a->guard_nord);
	free_stack(stack_a);
	return (0);
}

__attribute__((destructor)) static void destructor()
{
	system("leaks -q push_swap");
}
