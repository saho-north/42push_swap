/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:52:33 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/28 07:59:26 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (b->size == 0 && is_sorted(a, size))
		return ;
	else if (size < 7)
	{
		sort_small(a, b, size, STACK_A);
	}
	else if (b->size == 0 && is_reverse_sorted(a, size))
	{
		while (a->size > 0)
		{
			pb(a, b);
			rb(b);
		}
		while (b->size > 0)
		{
			pa(a, b);
		}
	}
	else
		partition(a, b, size, 0);
}
