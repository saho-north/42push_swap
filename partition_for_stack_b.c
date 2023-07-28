/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_for_stack_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 07:58:50 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/28 07:58:53 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_for_stack_b(t_stack *a, t_stack *b, int size)
{
	t_node	*guard;
	int		pivot;
	int		size_a;
	int		rb_count;
	int		i;

	// printf	("\n>>> partition_for_stack_b\n");
	print_stacks(a, b);
	guard = b->guard;
	if (size < 3 || b->size <= 3)
	{
		sort_small(b, a, size, STACK_B);
		while (b->size > 0 && size > 0)
		{
			pa(a, b);
			size--;
		}
		return ;
	}
	if (is_reverse_sorted(b, size))
	{
		// printf("reverse_sorted(b, %d) in partition_for_b\n", size);
		while (b->size > 0 && size > 0)
		{
			pa(a, b);
			size--;
		}
		return ;
	}
	pivot = get_pivot(b, size);
	// printf("size = %d, pivot = %d\n", size, pivot);
	size_a = 0;
	i = 0;
	while (i < size)
	{
		if (guard->next->value < pivot)
		{
			rb(b);
		}
		else
		{
			pa(a, b);
			size_a++;
		}
		i++;
	}
	rb_count = size - size_a;
	while (rb_count > 0)
	{
		rrb(b);
		rb_count--;
	}
	// printf("size_a = %d, size_b = %d\n", size_a, size - size_a);
	print_stacks(a, b);
	// printf("<<< partition_for_stack_b\n");
	partition(a, b, size_a, size - size_a);
}
