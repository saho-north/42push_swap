/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:03:42 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/11 04:42:50 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_doubly_linked_list(t_nord *guard_nord)
{
	t_nord	*node;
	t_nord	*next;

	if (!guard_nord)
		return ;
	node = guard_nord->next;
	while (node && node != guard_nord)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(guard_nord);
}

void	exit_with_print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_stack_and_exit_with_error(t_stack *stack)
{
	free_doubly_linked_list(stack->guard_nord);
	free(stack);
	exit_with_print_error();
}

void	free_stacks_exit_error(t_stack *stack_a, t_stack *stack_b)
{
	free_doubly_linked_list(stack_a->guard_nord);
	free_doubly_linked_list(stack_b->guard_nord);
	free(stack_a);
	free(stack_b);
	exit_with_print_error();
}
