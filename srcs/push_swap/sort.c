/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:52:33 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/09 03:06:56 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	{
		compaction(a);
		partition(a, b);
	}
}
