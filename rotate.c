/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:58:28 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/13 15:55:39 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
 */

static void	rotate(t_stack *stack)
{
	t_nord	*guard_nord;
	t_nord	*first_node;
	t_nord	*second_node;
	t_nord	*last_node;

	guard_nord = stack->guard_nord;
	if (guard_nord->next == guard_nord->prev)
		return ;
	first_node = guard_nord->next;
	second_node = first_node->next;
	last_node = guard_nord->prev;
	guard_nord->next = second_node;
	guard_nord->prev = first_node;
	first_node->next = guard_nord;
	first_node->prev = last_node;
	last_node->next = first_node;
	second_node->prev = guard_nord;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}
