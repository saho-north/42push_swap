/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 01:26:27 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/09 04:34:59 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_three_b(t_stack *b)
{
	t_node	*guard;
	int		first;
	int		second;
	int		last;

	guard = b->guard;
	first = guard->next->value;
	second = guard->next->next->value;
	last = guard->prev->value;
	if (first < second && first < last)
		rb(b);
	else if (first > second && second < last)
		rrb(b);
	first = guard->next->value;
	second = guard->next->next->value;
	if (first < second)
		sb(b);
}

static void	sort_three_a(t_stack *a)
{
	t_node	*guard;
	int		first;
	int		second;
	int		last;

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

static void	sort_four_five_six(t_stack *a, t_stack *b)
{
	t_node	*guard;
	size_t	to_move;

	guard = a->guard;
	to_move = a->size - 3;
	compaction(a);
	while (a->size > 3)
	{
		if (guard->next->index < to_move)
			pb(a, b);
		else if (guard->next->next->index < to_move)
			ra(a);
		else if (guard->prev->index < to_move)
			rra(a);
		else
			ra(a);
	}
	sort_small(a, b, 3, STACK_A);
	while (b->size > 0)
	{
		pa(a, b);
		if (guard->next->value > guard->next->next->value)
			sa(a);
	}
}

void	sort_small(t_stack *a, t_stack *b, size_t size, bool type)
{
	t_node	*node;

	if (type == STACK_A)
		node = a->guard->next;
	else
		node = b->guard->next;
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (type == STACK_A && node->value > node->next->value)
			sa(a);
		else if (type == STACK_B && node->value < node->next->value)
			sb(b);
	}
	else if (size == 3)
	{
		if (type == STACK_A)
			sort_three_a(a);
		else
			sort_three_b(b);
	}
	else if (size <= 6 && type == STACK_A)
		sort_four_five_six(a, b);
}
