/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_for_stack_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 07:58:33 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/31 19:18:38 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_for_stack_a(t_stack *a, t_stack *b, int size)
{
	t_node	*guard;
	int		pivot;
	int		size_b;
	int		i;
	int		ra_count;

	// printf("\n>>> partition_for_stack_a\n");
	print_stacks(a, b);
	guard = a->guard;
	if (size < 3 || a->size <= 3)
	{
		sort_small(a, b, size, STACK_A);
		return ;
	}
	if (is_sorted(a, size))
	{
		return ;
	}
	pivot = get_pivot(a, size);
	// printf("size = %d, pivot = %d\n", size, pivot);
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
	// else if (size == 4)
	// {
	// 	size_b = 0;
	// 	ra_count = 0;
	// 	while (size_b < 2)
	// 	{
	// 		if (guard->next->value < pivot)
	// 		{
	// 			pb(a, b);
	// 			size_b++;
	// 		}
	// 		else if (guard->next->next->value < pivot)
	// 		{
	// 			sa(a);
	// 			pb(a, b);
	// 			size_b++;
	// 		}
	// 		else
	// 		{
	// 			ra(a);
	// 			ra_count++;
	// 		}
	// 	}
	// 	while (ra_count > 0)
	// 	{
	// 		rra(a);
	// 		ra_count--;
	// 	}
	// 	if (guard->next->value > guard->next->next->value)
	// 	{
	// 		if (b->guard->next->value < b->guard->next->next->value)
	// 		{
	// 			ss(a, b);
	// 		}
	// 		else
	// 		{
	// 			sa(a);
	// 		}
	// 	}
	// 	else if (b->guard->next->value < b->guard->next->next->value)
	// 	{
	// 		sb(b);
	// 	}
	// 	while (size_b > 0)
	// 	{
	// 		pa(a, b);
	// 		size_b--;
	// 	}
	// 	return ;
	// }
	// else if (size == 5)
	// {
	// 	size_b = 0;
	// 	ra_count = 0;
	// 	while (size_b < 3)
	// 	{
	// 		if (guard->next->value < pivot)
	// 		{
	// 			pb(a, b);
	// 			size_b++;
	// 		}
	// 		else if (guard->next->value == pivot)
	// 		{
	// 			pb(a, b);
	// 			rb(b);
	// 			size_b++;
	// 		}
	// 		else if (guard->next->next->value < pivot)
	// 		{
	// 			sa(a);
	// 			pb(a, b);
	// 			size_b++;
	// 		}
	// 		else
	// 		{
	// 			ra(a);
	// 			ra_count++;
	// 		}
	// 	}
	// 	while (ra_count > 0)
	// 	{
	// 		rra(a);
	// 		ra_count--;
	// 	}
	// 	if (guard->next->value > guard->next->next->value)
	// 	{
	// 		if (b->guard->next->value < b->guard->next->next->value)
	// 		{
	// 			ss(a, b);
	// 		}
	// 		else
	// 		{
	// 			sa(a);
	// 		}
	// 	}
	// 	else if (b->guard->next->value < b->guard->next->next->value)
	// 	{
	// 		sb(b);
	// 	}
	// 	rrb(b);
	// 	while (size_b > 0)
	// 	{
	// 		pa(a, b);
	// 		size_b--;
	// 	}
	// 	return ;
	// }
	// else if (size == -1)
	// {
	// 	size_b = 0;
	// 	ra_count = 0;
	// 	while (size_b < 4)
	// 	{
	// 		if (guard->next->value < pivot)
	// 		{
	// 			pb(a, b);
	// 			size_b++;
	// 		}
	// 		else if (guard->next->next->value < pivot)
	// 		{
	// 			sa(a);
	// 			pb(a, b);
	// 			size_b++;
	// 		}
	// 		else if (guard->next->value == pivot)
	// 		{
	// 			pb(a, b);
	// 			rb(b);
	// 			size_b++;
	// 		}
	// 		else
	// 		{
	// 			ra(a);
	// 			ra_count++;
	// 		}
	// 	}
	// 	while (ra_count > 0)
	// 	{
	// 		rra(a);
	// 		ra_count--;
	// 	}
	// 	if (guard->next->value > guard->next->next->value)
	// 	{
	// 		if (b->guard->next->value < b->guard->next->next->value)
	// 		{
	// 			ss(a, b);
	// 		}
	// 		else
	// 		{
	// 			sa(a);
	// 		}
	// 	}
	// 	else if (b->guard->next->value < b->guard->next->next->value)
	// 	{
	// 		sb(b);
	// 	}
	// 	rrb(b);
	// 	while (size_b > 0)
	// 	{
	// 		pa(a, b);
	// 		size_b--;
	// 	}
	// 	return ;
	//}
	else
	{
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
		// printf("size_a = %d, size_b = %d\n", size - size_b, size_b);
		print_stacks(a, b);
		// printf("<<< partition_for_stack_a\n");
		partition(a, b, size - size_b, size_b);
	}
}
