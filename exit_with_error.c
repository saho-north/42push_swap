/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:14:08 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/28 09:14:09 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_doubly_linked_list(t_node *guard)
{
	t_node	*node;
	t_node	*next;

	if (!guard)
		return ;
	node = guard->next;
	while (node && node != guard)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(guard);
}

void	exit_with_print_error(void)
{
	ft_putendl_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_stack(t_stack *stack)
{
	free_doubly_linked_list(stack->guard);
	free(stack);
}

void	free_stack_with_print_error(t_stack *stack)
{
	free_stack(stack);
	exit_with_print_error();
}

void	free_stacks_with_print_error(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	exit_with_print_error();
}
