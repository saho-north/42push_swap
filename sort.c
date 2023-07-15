/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 01:26:27 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/15 05:28:21 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_value(t_stack *stack)
{
	t_nord	*node;
	int		min;

	node = stack->guard_nord->next;
	min = node->value;
	while (node != stack->guard_nord)
	{
		if (min > node->value)
			min = node->value;
		node = node->next;
	}
	return (min);
}

void	sort_three_b(t_stack *stack_b)
{
	t_nord	*guard_node;
	int		first;
	int		second;
	int		last;

	printf("sort_three_b\n");
	guard_node = stack_b->guard_nord;
	first = guard_node->next->value;
	second = guard_node->next->next->value;
	last = guard_node->prev->value;
	while (first < second || second < last)
	{
		if (first < second && second > last && first < last)
			rb(stack_b);
		else if (first > second && second < last && first < last)
			rrb(stack_b);
		else
			sb(stack_b);
		first = guard_node->next->value;
		second = guard_node->next->next->value;
		last = guard_node->prev->value;
	}
}

void	sort_small_b(t_stack *stack_b)
{
	t_nord	*node;
	int		size;

	printf("sort_small_b\n");
	size = stack_b->size;
	node = stack_b->guard_nord->next;
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if (node->value > node->next->value)
			sb(stack_b);
	}
	else if (size == 3)
		sort_three_b(stack_b);
}

void	sort_three_a(t_stack *stack_a)
{
	t_nord	*guard_node;
	int		first;
	int		second;
	int		last;

	printf("sort_three_a\n");
	guard_node = stack_a->guard_nord;
	first = guard_node->next->value;
	second = guard_node->next->next->value;
	last = guard_node->prev->value;
	while (first > second || second > last)
	{
		if (first > second && second < last && first > last)
			ra(stack_a);
		else if (first < second && second > last && first > last)
			rra(stack_a);
		else
			sa(stack_a);
		first = guard_node->next->value;
		second = guard_node->next->next->value;
		last = guard_node->prev->value;
	}
}

bool	is_sorted(t_stack *stack)
{
	t_nord	*guard_node;
	t_nord	*node;

	guard_node = stack->guard_nord;
	node = guard_node->next;
	while (node != guard_node && node->next != guard_node)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}

void	sort_six_or_less(t_stack *stack_a, t_stack *stack_b)
{
	t_nord	*guard_a;
	int		min;

	printf("sort_six_or_less\n");
	guard_a = stack_a->guard_nord;
	if (is_sorted(stack_a))
		return ;
	while (stack_a->size > 3)
	{
		min = get_min_value(stack_a);
		if (guard_a->next->value == min)
			pb(stack_a, stack_b);
		else if (guard_a->prev->value == min)
			rra(stack_a);
		else if (guard_a->prev->prev->value == min)
			rra(stack_a);
		else
			ra(stack_a);
	}
	sort_three_a(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_nord	*node;
	int		size;

	node = stack_a->guard_nord->next;
	size = stack_a->size;
	if (size == 1)
	{
		printf("sort_one_a\n");
		return ;
	}
	else if (size == 2)
	{
		printf("sort_two_a\n");
		if (node->value > node->next->value)
			sa(stack_a);
	}
	else if (size == 3)
		sort_three_a(stack_a);
	else if (size < 7)
		sort_six_or_less(stack_a, stack_b);
	else
		quicksort(stack_a, stack_b);
}
