/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:55:38 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/01 03:31:26 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int size -> size_t size に変更
// largeとmediumは同数であることが保障されているので、デバックが済んだら削除できる
// また、largeとmediumの数を数える変数は不要である

void	partition_for_a(t_stack *a, t_stack *b, size_t size, size_t max_id)
{
	size_t	i;
	size_t	pivot_left;
	size_t	pivot_right;
	size_t	small_count;
	size_t	medium_count;
	size_t	large_count;

	printf("\n>>> partition_for_stack_a\n");
	print_stacks(a, b);
	if (is_sorted(a, size) || size < 2)
	{
		return ;
	}
	if (size < 3 || a->size <= 3)
	{
		sort_small(a, b, size, STACK_A);
		return ;
	}
	pivot_left = max_id - (size / 3) * 2;
	pivot_right = max_id - size / 3;
	small_count = 0;
	medium_count = 0;
	large_count = 0;
	i = 0;
	while (i < size)
	{
		if (a->guard->next->index > pivot_right)
		{
			ra(a);
			large_count++;
		}
		else if (a->guard->next->index > pivot_left)
		{
			pb(a, b);
			rb(b);
			medium_count++;
		}
		else
		{
			pb(a, b);
			small_count++;
		}
		i++;
	}
	i = 0;
	while (i < large_count && i < medium_count)
	{
		rrr(a, b);
		i++;
	}
	// この箇所はデバックが済んだら削除する
	if (large_count != medium_count)
		printf("the number of large and medium is not same\n");
	printf("after sorting\n");
	print_stacks(a, b);
	printf("<<< partition_for_stack_a\n");
	if (large_count > 0)
	{
		partition_for_a(a, b, large_count, max_id);
	}
	if (medium_count > 0)
	{
		partition_for_b(a, b, medium_count, pivot_left + 1);
	}
	if (small_count > 0)
	{
		partition_for_b(a, b, small_count, max_id + 1 - size);
	}
}
