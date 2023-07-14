/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 01:26:27 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/15 02:06:36 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_stack *stack)
{
	int	first;
	int	second;
	int	last;

	first = stack->guard_nord->next->value;
	second = stack->guard_nord->next->next->value;
	last = stack->guard_nord->prev->value;
	while (first > second || second > last)
	{
		if (first > second && second < last && first > last)
			ra(stack);
		else if (first < second && second > last && first > last)
			rra(stack);
		else
			sa(stack);
		first = stack->guard_nord->next->value;
		second = stack->guard_nord->next->next->value;
		last = stack->guard_nord->prev->value;
	}
}

int	min_value(t_stack *stack)
{
	t_nord	*guard_node;
	t_nord	*node;
	int		min;

	guard_node = stack->guard_nord;
	node = guard_node->next;
	min = INT_MAX;
	while (node != guard_node)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	return (min);
}

void	sort_six_or_less(t_stack *stack_a, t_stack *stack_b)
{
	t_nord	*guard_node;
	int		min;

	guard_node = stack_a->guard_nord;
	while (stack_a->size > 3)
	{
		min = min_value(stack_a);
		while (guard_node->next->value != min)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three_a(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

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

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a->size;
	if (size == 1)
		return ;
	else if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three_a(stack_a);
	else if (size < 7)
		sort_six_or_less(stack_a, stack_b);
	else
		quicksort(stack_a, stack_b);
}
