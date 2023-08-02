/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:58:28 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/02 14:54:05 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
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

void	ra(t_stack *a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
