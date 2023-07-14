/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:28:36 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/15 02:57:24 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
*/

static void	push(t_stack *stack_from, t_stack *stack_to)
{
	t_nord	*nord_to_push;
	t_nord	*guard_from;
	t_nord	*guard_to;

	guard_from = stack_from->guard_nord;
	guard_to = stack_to->guard_nord;
	nord_to_push = stack_from->guard_nord->next;
	if (nord_to_push == guard_from)
		return ;
	guard_from->next = nord_to_push->next;
	nord_to_push->next->prev = guard_from;
	stack_from->size--;
	nord_to_push->next = guard_to->next;
	nord_to_push->prev = guard_to;
	guard_to->next = nord_to_push;
	nord_to_push->next->prev = nord_to_push;
	stack_to->size++;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
	printf("stack_a : ");
	print_stack(stack_a);
	printf("stack_b : ");
	print_stack(stack_b);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
	printf("stack_a : ");
	print_stack(stack_a);
	printf("stack_b : ");
	print_stack(stack_b);
}
