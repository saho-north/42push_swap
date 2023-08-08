/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 04:20:21 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/09 03:03:18 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

static void	do_partition(t_stack *a, t_stack *b, size_t size, size_t max_id)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (a->guard->next->index > max_id - size / 3)
			ra(a);
		else if (a->guard->next->index > max_id - (size / 3) * 2)
		{
			pb(a, b);
			if (i + 1 < size && a->guard->next->index > max_id - size / 3)
			{
				rr(a, b);
				i++;
			}
			else
				rb(b);
		}
		else
		{
			pb(a, b);
		}
		i++;
	}
}

void	partition_a(t_stack *a, t_stack *b, size_t size, size_t max_id)
{
	if (size < 2 || is_sorted(a, size))
		return ;
	else if (size < 3 || a->size <= 3)
		sort_small(a, b, size, STACK_A);
	else if (size == 3)
		sort_top_3_a(a);
	else
	{
		do_partition(a, b, size, max_id);
		multi_rrr(a, b, size / 3);
		partition_a(a, b, size / 3, max_id);
		partition_b(a, b, size / 3, max_id - (size / 3) * 2 + 1);
		partition_b(a, b, size - (size / 3) * 2, max_id + 1 - size);
	}
}

static void	do_1stpartition(t_stack *a, t_stack *b, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (a->guard->next->index >= (size / 3) * 2)
			ra(a);
		else if (a->guard->next->index >= size / 3)
			pb(a, b);
		else
		{
			pb(a, b);
			if (i + 1 < size && a->guard->next->index >= (size / 3) * 2)
			{
				rr(a, b);
				i++;
			}
			else
				rb(b);
		}
		i++;
	}
}

void	partition(t_stack *a, t_stack *b)
{
	size_t	size;

	size = a->size;
	if (size < 2 || is_sorted(a, size))
		return ;
	else if (size < 3 || a->size <= 3)
		sort_small(a, b, size, STACK_A);
	else if (size == 3)
		sort_top_3_a(a);
	else
	{
		do_1stpartition(a, b, size);
		partition_a(a, b, size - (size / 3) * 2, size - 1);
		partition_b(a, b, size / 3, size / 3);
		partition_b(a, b, size / 3, 0);
	}
}
