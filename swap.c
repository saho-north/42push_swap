/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:06:42 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/15 13:21:43 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
 */

static void	swap(t_stack *stack)
{
	t_nord	*guard_nord;
	t_nord	*first_node;
	t_nord	*second_node;

	guard_nord = stack->guard_nord;
	first_node = guard_nord->next;
	second_node = first_node->next;
	if (first_node == guard_nord || second_node == guard_nord)
		return ;
	first_node->next = second_node->next;
	first_node->prev = second_node;
	first_node->next->prev = first_node;
	second_node->next = first_node;
	second_node->prev = guard_nord;
	guard_nord->next = second_node;
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
	printf("stack_a : ");
	print_stack(stack_a);
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
	printf("stack_b : ");
	print_stack(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	print_stacks(stack_a, stack_b);
}
