/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 04:20:21 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/02 08:51:15 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition_for_a(t_stack *a, t_stack *b, size_t size, size_t max_id);
static void	partition_for_b(t_stack *a, t_stack *b, size_t size, size_t min_id);

static void	push_sorted_nodes(t_stack *a, t_stack *b, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		pa(a, b);
		i++;
	}
}

static void	sort_push_top_3_b(t_stack *a, t_stack *b, size_t min_id)
{
	size_t	pa_count;

	pa_count = 0;
	while (pa_count < 3)
	{
		if (b->guard->next->index != min_id || pa_count != 0)
		{
			pa(a, b);
			pa_count++;
		}
		if (a->guard->next->index > a->guard->next->next->index)
		{
			if (b->guard->next->index < b->guard->next->next->index)
				ss(a, b);
			else
				sa(a);
		}
		if (b->guard->next->index < b->guard->next->next->index)
			sb(b);
	}
}

static void	partition_for_b(t_stack *a, t_stack *b, size_t size, size_t min_id)
{
	size_t	i;
	size_t	pivot_left;
	size_t	pivot_right;
	size_t	push_count;

	if (size < 3 || b->size <= 3)
	{
		sort_small(a, b, size, STACK_B);
		push_sorted_nodes(a, b, size);
		return ;
	}
	if (is_reverse_sorted(b, size))
	{
		push_sorted_nodes(a, b, size);
		return ;
	}
	if (size == 3)
	{
		sort_push_top_3_b(a, b, min_id);
		return ;
	}
	pivot_left = min_id + size / 3;
	pivot_right = min_id + (size / 3) * 2;
	push_count = 0;
	i = 0;
	while (i < size)
	{
		if (b->guard->next->index < pivot_left)
		{
			rb(b);
		}
		else if (b->guard->next->index < pivot_right)
		{
			pa(a, b);
			if (i + 1 < size && b->guard->next->index < pivot_left)
			{
				rr(a, b);
				i++;
			}
			else
			{
				ra(a);
			}
		}
		else
		{
			pa(a, b);
			push_count++;
		}
		i++;
	}
	partition_for_a(a, b, push_count, pivot_right + push_count - 1);
	i = 0;
	while (i < (size - push_count) / 2)
	{
		rrr(a, b);
		i++;
	}
	partition_for_a(a, b, (size - push_count) / 2, pivot_right - 1);
	partition_for_b(a, b, (size - push_count) / 2, min_id);
}

static void	sort_top_3_a(t_stack *a)
{
	size_t	first;
	size_t	second;
	size_t	third;

	while (1)
	{
		first = a->guard->next->index;
		second = a->guard->next->next->index;
		third = a->guard->next->next->next->index;
		if (first < second && second < third)
			break ;
		if (first > second)
			sa(a);
		else
		{
			ra(a);
			sa(a);
			rra(a);
		}
	}
}

static void	partition_for_a(t_stack *a, t_stack *b, size_t size, size_t max_id)
{
	size_t	i;
	size_t	pivot_left;
	size_t	pivot_right;
	size_t	push_count;

	if (size < 2 || is_sorted(a, size))
	{
		return ;
	}
	if (size < 3 || a->size <= 3)
	{
		sort_small(a, b, size, STACK_A);
		return ;
	}
	if (size == 3)
	{
		sort_top_3_a(a);
		return ;
	}
	pivot_left = max_id - (size / 3) * 2;
	pivot_right = max_id - size / 3;
	push_count = 0;
	i = 0;
	while (i < size)
	{
		if (a->guard->next->index > pivot_right)
		{
			ra(a);
		}
		else if (a->guard->next->index > pivot_left)
		{
			pb(a, b);
			if (i + 1 < size && a->guard->next->index > pivot_right)
			{
				rr(a, b);
				i++;
			}
			else
			{
				rb(b);
			}
		}
		else
		{
			pb(a, b);
			push_count++;
		}
		i++;
	}
	i = 0;
	while (i < (size - push_count) / 2)
	{
		rrr(a, b);
		i++;
	}
	partition_for_a(a, b, (size - push_count) / 2, max_id);
	partition_for_b(a, b, (size - push_count) / 2, pivot_left + 1);
	partition_for_b(a, b, push_count, max_id + 1 - size);
}

void	partition(t_stack *a, t_stack *b)
{
	partition_for_a(a, b, a->size, a->size - 1);
}
