/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 01:26:27 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/19 21:20:24 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_b(t_stack *b)
{
	t_node	*guard;
	int		first;
	int		second;
	int		last;

	printf("sort_three_b\n");
	guard = b->guard;
	first = guard->next->value;
	second = guard->next->next->value;
	last = guard->prev->value;
	if (first > second && first > last)
		rb(b);
	else if (first < second && second > last)
		rrb(b);
	first = guard->next->value;
	second = guard->next->next->value;
	if (first > second)
		sb(b);
}

static void	sort_three_a(t_stack *a)
{
	t_node	*guard;
	int		first;
	int		second;
	int		last;

	printf("sort_three_a\n");
	guard = a->guard;
	first = guard->next->value;
	second = guard->next->next->value;
	last = guard->prev->value;
	if (first > second && first > last)
		ra(a);
	else if (first < second && second > last)
		rra(a);
	first = guard->next->value;
	second = guard->next->next->value;
	if (first > second)
		sa(a);
}

static int	get_min_value(t_stack *stack)
{
	t_node	*node;
	int		min;

	node = stack->guard->next;
	min = node->value;
	while (node != stack->guard)
	{
		if (min > node->value)
			min = node->value;
		node = node->next;
	}
	return (min);
}

static void	sort_six_or_less(t_stack *a, t_stack *b)
{
	t_node	*guard_a;
	int		min;

	printf("sort_six_or_less\n");
	guard_a = a->guard;
	while (a->size != 3)
	{
		min = get_min_value(a);
		if (guard_a->next->value == min)
			pb(a, b);
		else if (guard_a->prev->value == min)
			rra(a);
		else if (guard_a->prev->prev->value == min)
			rra(a);
		else
			ra(a);
	}
	sort_three_a(a);
	while (b->size > 0)
		pa(a, b);
}

void	sort_small(t_stack *to_sort, t_stack *sub, bool stack_type)
{
	int		size;
	t_node	*node;

	node = to_sort->guard->next;
	size = to_sort->size;
	if (size <= 1)
		return ;
	if (size == 2 && node->value > node->next->value)
	{
		if (stack_type == STACK_A)
			sa(to_sort);
		else
			sb(to_sort);
	}
	else if (size == 3)
	{
		if (stack_type == STACK_A)
			sort_three_a(to_sort);
		else
			sort_three_b(to_sort);
	}
	else if (size <= 6 && stack_type == STACK_A)
		sort_six_or_less(to_sort, sub);
}
