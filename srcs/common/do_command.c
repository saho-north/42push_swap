/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 03:18:18 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 22:44:27 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_common.h"

void	swap(t_stack *stack)
{
	t_node	*guard;
	t_node	*first_node;
	t_node	*second_node;

	guard = stack->guard;
	first_node = guard->next;
	second_node = first_node->next;
	if (first_node == guard || second_node == guard)
		return ;
	first_node->next = second_node->next;
	first_node->prev = second_node;
	first_node->next->prev = first_node;
	second_node->next = first_node;
	second_node->prev = guard;
	guard->next = second_node;
}

void	push(t_stack *stack_from, t_stack *stack_to)
{
	t_node	*node_to_push;
	t_node	*guard_from;
	t_node	*guard_to;

	guard_from = stack_from->guard;
	guard_to = stack_to->guard;
	node_to_push = stack_from->guard->next;
	if (node_to_push == guard_from)
		return ;
	guard_from->next = node_to_push->next;
	node_to_push->next->prev = guard_from;
	stack_from->size--;
	node_to_push->next = guard_to->next;
	node_to_push->prev = guard_to;
	guard_to->next = node_to_push;
	node_to_push->next->prev = node_to_push;
	stack_to->size++;
}

void	rotate(t_stack *stack)
{
	t_node	*guard;
	t_node	*first_node;
	t_node	*second_node;
	t_node	*last_node;

	guard = stack->guard;
	if (guard->next == guard->prev)
		return ;
	first_node = guard->next;
	second_node = first_node->next;
	last_node = guard->prev;
	guard->next = second_node;
	guard->prev = first_node;
	first_node->next = guard;
	first_node->prev = last_node;
	last_node->next = first_node;
	second_node->prev = guard;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*guard;
	t_node	*first_node;
	t_node	*last_node;
	t_node	*second_last_node;

	guard = stack->guard;
	if (guard->next == guard->prev)
		return ;
	first_node = guard->next;
	last_node = guard->prev;
	second_last_node = last_node->prev;
	guard->next = last_node;
	guard->prev = second_last_node;
	last_node->next = first_node;
	last_node->prev = guard;
	second_last_node->next = guard;
	first_node->prev = last_node;
}
