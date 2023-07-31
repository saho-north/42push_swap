/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:55:38 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/01 00:58:31 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//int size -> size_t size に変更

void	partition_for_a(t_stack *a, t_stack *b, size_t size)
{
	t_node	*guard;
	int		pivot;
	int		size_b;
	int		ra_count;
	size_t	i;

	guard = a->guard;
	if (size < 3 || a->size <= 3)
	{
		sort_small(a, b, size, STACK_A);
		return ;
	}
	else if (is_sorted(a, size))
	{
		return ;
	}
	else
	{
		//まずpivotを二つ決めて、3つのグループに分ける
		pivot = get_pivot(a, size);
		size_b = 0;
		i = 0;
		while (i < size)
		{
			if (guard->next->value < pivot)
			{
				pb(a, b);
				size_b++;
			}
			else
			{
				ra(a);
			}
			i++;
		}
		ra_count = size - size_b;
		while (a->size != size - size_b && ra_count > 0)
		{
			rra(a);
			ra_count--;
		}
		printf("size_a = %d, size_b = %d\n", size - size_b, size_b);
		print_stacks(a, b);
		printf("<<< partition_for_stack_a\n");
		partition(a, b, size - size_b, size_b);
	}
}

/*
	if (size == 3)
	{
		while (!is_sorted(a, size))
		{
			if (guard->next->value > guard->next->next->value)
			{
				sa(a);
			}
			else
			{
				ra(a);
				sa(a);
				rra(a);
			}
		}
		return ;
	}
	else if (size == 4)
	{
		size_b = 0;
		ra_count = 0;
		while (size_b < 2)
		{
			if (guard->next->value < pivot)
			{
				pb(a, b);
				size_b++;
			}
			else if (guard->next->next->value < pivot)
			{
				sa(a);
				pb(a, b);
				size_b++;
			}
			else
			{
				ra(a);
				ra_count++;
			}
		}
		while (ra_count > 0)
		{
			rra(a);
			ra_count--;
		}
		if (guard->next->value > guard->next->next->value)
		{
			if (b->guard->next->value < b->guard->next->next->value)
			{
				ss(a, b);
			}
			else
			{
				sa(a);
			}
		}
		else if (b->guard->next->value < b->guard->next->next->value)
		{
			sb(b);
		}
		while (size_b > 0)
		{
			pa(a, b);
			size_b--;
		}
		return ;
	}
	else if (size == 5)
	{
		size_b = 0;
		ra_count = 0;
		while (size_b < 3)
		{
			if (guard->next->value < pivot)
			{
				pb(a, b);
				size_b++;
			}
			else if (guard->next->value == pivot)
			{
				pb(a, b);
				rb(b);
				size_b++;
			}
			else if (guard->next->next->value < pivot)
			{
				sa(a);
				pb(a, b);
				size_b++;
			}
			else
			{
				ra(a);
				ra_count++;
			}
		}
		while (ra_count > 0)
		{
			rra(a);
			ra_count--;
		}
		if (guard->next->value > guard->next->next->value)
		{
			if (b->guard->next->value < b->guard->next->next->value)
			{
				ss(a, b);
			}
			else
			{
				sa(a);
			}
		}
		else if (b->guard->next->value < b->guard->next->next->value)
		{
			sb(b);
		}
		rrb(b);
		while (size_b > 0)
		{
			pa(a, b);
			size_b--;
		}
		return ;
	}
	else if (size == -1)
	{
		size_b = 0;
		ra_count = 0;
		while (size_b < 4)
		{
			if (guard->next->value < pivot)
			{
				pb(a, b);
				size_b++;
			}
			else if (guard->next->next->value < pivot)
			{
				sa(a);
				pb(a, b);
				size_b++;
			}
			else if (guard->next->value == pivot)
			{
				pb(a, b);
				rb(b);
				size_b++;
			}
			else
			{
				ra(a);
				ra_count++;
			}
		}
		while (ra_count > 0)
		{
			rra(a);
			ra_count--;
		}
		if (guard->next->value > guard->next->next->value)
		{
			if (b->guard->next->value < b->guard->next->next->value)
			{
				ss(a, b);
			}
			else
			{
				sa(a);
			}
		}
		else if (b->guard->next->value < b->guard->next->next->value)
		{
			sb(b);
		}
		rrb(b);
		while (size_b > 0)
		{
			pa(a, b);
			size_b--;
		}
		return ;
	}
 */

void	partition(t_stack *a, t_stack *b, int size_a, int size_b)
{
	if (size_a > 0)
	{
		partition_for_stack_a(a, b, size_a);
	}
	if (size_b > 0)
	{
		partition_for_stack_b(a, b, size_b);
	}
}
