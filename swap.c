/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:06:42 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/12 18:22:37 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 The rules
• You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
◦ The stack b is empty.
• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:
sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
ss: sa and sb at the same time.
*/

void	sa(t_stack *stack)
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
