/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:52:33 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/31 22:47:37 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
	int	size;

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
		partition(a, b, size, 0);
}
