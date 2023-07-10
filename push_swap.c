/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:04:22 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/11 05:40:35 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_nord *guard_nord)
{
	t_nord	*ptr;

	ptr = guard_nord;
	if (guard_nord == NULL)
	{
		return ;
	}
	while (ptr->next != guard_nord)
	{
		printf("%d ", ptr->value);
		ptr = ptr->next;
	}
	printf("guard_nord: %d\n", ptr->value);
}

int	main(int argc, const char **argv)
{
	t_stack	*stack_a;

	if (argc == 1 || !is_valid_arg(--argc, ++argv))
	{
		printf("Not valid\n");
		exit_with_print_error();
	}
	stack_a = parse_input(argc, argv);
	if (!stack_a)
		exit_with_print_error();
	//print_stack(stack_a->guard_nord);
	free_stack_and_exit_with_error(stack_a);
	return (0);
}

__attribute__((destructor)) static void destructor()
{
	system("leaks -q push_swap");
}
