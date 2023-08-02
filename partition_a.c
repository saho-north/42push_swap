/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 04:20:21 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/02 10:08:56 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	partition_a(t_stack *a, t_stack *b, size_t size, size_t max_id)
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
	partition_a(a, b, (size - push_count) / 2, max_id);
	partition_b(a, b, (size - push_count) / 2, pivot_left + 1);
	partition_b(a, b, push_count, max_id + 1 - size);
}
