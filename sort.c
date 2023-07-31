/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:52:33 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/01 03:09:17 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
	size_t	size;

	size = a->size;
	if (size < 7)
	{
		sort_small(a, b, size, STACK_A);
	}
	else if (is_reverse_sorted(a, size))
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
		partition_for_a(a, b, size, size - 1);
}
