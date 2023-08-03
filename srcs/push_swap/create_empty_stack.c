/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_empty_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:46:06 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 08:06:16 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_node	*create_guard(void)
{
	t_node	*guard;

	guard = (t_node *)malloc(sizeof(t_node));
	if (!guard)
		return (NULL);
	guard->next = guard;
	guard->prev = guard;
	guard->value = 0;
	return (guard);
}

t_stack	*create_empty_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit_with_print_error();
	stack->guard = create_guard();
	if (!stack->guard)
	{
		free(stack);
		exit_with_print_error();
	}
	stack->size = 0;
	return (stack);
}
