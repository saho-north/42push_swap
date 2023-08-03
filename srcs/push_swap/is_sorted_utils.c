/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 07:52:46 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 08:06:59 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	is_reverse_sorted(t_stack *stack, size_t size)
{
	t_node	*guard;
	t_node	*node;

	guard = stack->guard;
	node = guard->next;
	while (node != guard && node->next != guard && size > 1)
	{
		if (node->value < node->next->value)
			return (false);
		node = node->next;
		size--;
	}
	return (true);
}

bool	is_sorted(t_stack *stack, size_t size)
{
	t_node	*guard;
	t_node	*node;

	guard = stack->guard;
	node = guard->next;
	while (node != guard && node->next != guard && size > 1)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
		size--;
	}
	return (true);
}
