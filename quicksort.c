/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 01:26:27 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/15 03:28:58 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(t_stack *stack)
{
	t_nord	*node;
	int		size;
	int		i;

	node = stack->guard_nord->next;
	size = stack->size;
	i = 0;
	while (i < size / 2)
	{
		node = node->next;
		i++;
	}
	return (node->value);
}

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	t_nord	*guard_node;
	int		pivot;
	int		size;

	if (stack_a->size <= 3)
		return (sort(stack_a, stack_b));
	guard_node = stack_a->guard_nord;
	pivot = get_pivot(stack_a);
	size = stack_a->size;
	while (size-- > 0 && stack_a->size > 3)
	{
		if (guard_node->next->value < pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort(stack_a, stack_b);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}
