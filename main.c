/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:04:22 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/09 04:01:20 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack_a)
{
	t_list	*ptr;

	ptr = stack_a;
	if (stack_a == NULL)
	{
		return ;
	}
	while (ptr->next != stack_a)
	{
		printf("%d ", ptr->value);
		ptr = ptr->next;
	}
	printf("%d\n", ptr->value);
	printf("OK\n");
}

int	main(int argc, const char **argv)
{
	t_list	*stack_a;

	if (argc == 1 || !is_valid_arg(--argc, ++argv))
		print_error();
	stack_a = stack_init(argc, argv);
	if (!stack_a)
		print_error();
	print_stack(stack_a);
	lst_clear(&stack_a);
	return (0);
}

__attribute__((destructor)) static void destructor()
{
	system("leaks -q push_swap");
}
