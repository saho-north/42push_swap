/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 04:20:21 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/02 01:25:27 by sakitaha         ###   ########.fr       */
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

static void	partition_for_b(t_stack *a, t_stack *b, size_t size, size_t min_id)
{
	size_t	i;
	size_t	pivot_left;
	size_t	pivot_right;
	size_t	small_count;
	size_t	medium_count;
	size_t	large_count;

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
	pivot_left = min_id + size / 3;
	pivot_right = min_id + (size / 3) * 2;
	small_count = 0;
	medium_count = 0;
	large_count = 0;
	i = 0;
	while (i < size)
	{
		if (b->guard->next->index < pivot_left)
		{
			rb(b);
			small_count++;
		}
		else if (b->guard->next->index < pivot_right)
		{
			pa(a, b);
			if (i + 1 < size && b->guard->next->index < pivot_left)
			{
				rr(a, b);
				medium_count++;
				small_count++;
				i++;
			}
			else
			{
				ra(a);
				medium_count++;
			}
		}
		else
		{
			pa(a, b);
			large_count++;
		}
		i++;
	}
	partition_for_a(a, b, large_count, pivot_right + large_count - 1);
	i = 0;
	while (i < small_count && i < medium_count)
	{
		rrr(a, b);
		i++;
	}
	partition_for_a(a, b, medium_count, pivot_right - 1);
	partition_for_b(a, b, small_count, min_id);
}

static void	sort_top_3_a(t_stack *a)
{
	size_t	first;
	size_t	second;
	size_t	third;

	while (true)
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
	size_t	small_count;
	size_t	medium_count;
	size_t	large_count;

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
	small_count = 0;
	medium_count = 0;
	large_count = 0;
	i = 0;
	while (i < size)
	{
		if (a->guard->next->index > pivot_right)
		{
			ra(a);
			large_count++;
		}
		else if (a->guard->next->index > pivot_left)
		{
			pb(a, b);
			if (i + 1 < size && a->guard->next->index > pivot_right)
			{
				rr(a, b);
				large_count++;
				medium_count++;
				i++;
			}
			else
			{
				rb(b);
				medium_count++;
			}
		}
		else
		{
			pb(a, b);
			small_count++;
		}
		i++;
	}
	i = 0;
	while (i < large_count && i < medium_count)
	{
		rrr(a, b);
		i++;
	}
	partition_for_a(a, b, large_count, max_id);
	partition_for_b(a, b, medium_count, pivot_left + 1);
	partition_for_b(a, b, small_count, max_id + 1 - size);
}

void	partition(t_stack *a, t_stack *b)
{
	partition_for_a(a, b, a->size, a->size - 1);
}
