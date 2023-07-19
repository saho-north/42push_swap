/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:20:44 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/19 14:10:14 by sakitaha         ###   ########.fr       */
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
