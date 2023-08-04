/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 04:20:21 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/05 02:17:53 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

static void	do_partition(t_stack *a, t_stack *b, size_t size, size_t min_id)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (b->guard->next->index < min_id + size / 3)
			rb(b);
		else if (b->guard->next->index < min_id + (size / 3) * 2)
		{
			pa(a, b);
			if (i + 1 < size && b->guard->next->index < min_id + size / 3)
			{
				rr(a, b);
				i++;
			}
			else
				ra(a);
		}
		else
			pa(a, b);
		i++;
	}
}

void	partition_b(t_stack *a, t_stack *b, size_t size, size_t min_id)
{
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
	do_partition(a, b, size, min_id);
	partition_a(a, b, size - (size / 3) * 2, min_id + size - 1);
	multi_rrr(a, b, size / 3);
	partition_a(a, b, size / 3, min_id + (size / 3) * 2 - 1);
	partition_b(a, b, size / 3, min_id);
}
