/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:20:44 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/15 22:39:45 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.
*/

static void	reverse_rotate(t_stack *stack)
{
	t_nord	*guard_nord;
	t_nord	*first_node;
	t_nord	*last_node;
	t_nord	*second_last_node;

	guard_nord = stack->guard_nord;
	if (guard_nord->next == guard_nord->prev)
		return ;
	first_node = guard_nord->next;
	last_node = guard_nord->prev;
	second_last_node = last_node->prev;
	guard_nord->next = last_node;
	guard_nord->prev = second_last_node;
	last_node->next = first_node;
	last_node->prev = guard_nord;
	second_last_node->next = guard_nord;
	first_node->prev = last_node;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	ft_putendl_fd("rra", 1);
	printf("a : ");
	print_stack(a);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_putendl_fd("rrb", 1);
	printf("b : ");
	print_stack(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
	print_stacks(a, b);
}
