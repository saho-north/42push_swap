/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:06:42 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/12 21:17:59 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
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
}

void	sb(t_stack *stack)
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
	second_node->next->prev = first_node;
	second_node->next = first_node;
	first_node->prev = second_node;
	guard_nord->next = second_node;
	second_node->prev = guard_nord;
}
