/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 04:20:21 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/01 07:06:32 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition_for_a(t_stack *a, t_stack *b, size_t size, size_t max_id);
static void	partition_for_b(t_stack *a, t_stack *b, size_t size, size_t min_id);

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

static void	partition_for_b(t_stack *a, t_stack *b, size_t size, size_t min_id)
{
	size_t	i;
	size_t	pivot_left;
	size_t	pivot_right;
	size_t	small_count;
	size_t	medium_count;
	size_t	large_count;

	//printf("\n>>> partition_for_stack_b\n");
	print_stack_size(b, size);
	//printf("min_id = %zu, max_id = %zu\n", min_id, min_id + size - 1);
	print_stacks(a, b);
	// ここの中身の動作が正しいか、あとで確認する
	if (size < 3 || b->size <= 3)
	{
		//printf("size < 3 || b->size <= 3\n");
		print_stack_size(b, size);
		//printf("sort_small\n");
		sort_small(a, b, size, STACK_B);
		print_stack_size(b, size);
		push_sorted_nodes(a, b, size);
		return ;
	}
	if (is_reverse_sorted(b, size))
	{
		//printf("b is reverse sorted\n");
		push_sorted_nodes(a, b, size);
		return ;
	}
	pivot_left = min_id + size / 3;
	pivot_right = min_id + (size / 3) * 2;
	//printf("pivot_left = %zu, pivot_right = %zu\n", pivot_left, pivot_right);
	small_count = 0;
	medium_count = 0;
	large_count = 0;
	i = 0;
	while (i < size)
	{
		if (b->guard->next->index < pivot_left)
		{
			//printf("small\n");
			rb(b);
			small_count++;
		}
		else if (b->guard->next->index < pivot_right)
		{
			//printf("medium\n");
			pa(a, b);
			ra(a);
			medium_count++;
		}
		else
		{
			//printf("large\n");
			pa(a, b);
			large_count++;
		}
		i++;
	}
	//printf("after sorting\n");
	print_stacks(a, b);
	//printf("<<< partition_for_stack_b\n");
	if (large_count > 0)
	{
		partition_for_a(a, b, large_count, pivot_right + large_count - 1);
	}
	i = 0;
	while (i < small_count && i < medium_count)
	{
		rrr(a, b);
		i++;
	}
	if (medium_count > 0)
	{
		partition_for_a(a, b, medium_count, pivot_right - 1);
	}
	if (small_count > 0)
	{
		partition_for_b(a, b, small_count, min_id);
	}
}

// int size -> size_t size に変更
// largeとmediumは同数であることが保障されているので、デバックが済んだら削除できる
// また、largeとmediumの数を数える変数は不要である

static void	partition_for_a(t_stack *a, t_stack *b, size_t size, size_t max_id)
{
	size_t	i;
	size_t	pivot_left;
	size_t	pivot_right;
	size_t	small_count;
	size_t	medium_count;
	size_t	large_count;

	//printf("\n>>> partition_for_stack_a\n");
	print_stack_size(a, size);
	//printf("min_id = %zu, max_id = %zu\n", max_id - size + 1, max_id);
	print_stacks(a, b);
	if (size < 2)
	{
		//printf("size < 2\n");
		return ;
	}
	if (is_sorted(a, size))
	{
		//printf("sorted\n");
		return ;
	}
	if (size < 3 || a->size <= 3)
	{
		//printf("size < 3 || a->size <= 3\n");
		sort_small(a, b, size, STACK_A);
		return ;
	}
	pivot_left = max_id - (size / 3) * 2;
	pivot_right = max_id - size / 3;
	//printf("pivot_left = %zu, pivot_right = %zu\n", pivot_left, pivot_right);
	small_count = 0;
	medium_count = 0;
	large_count = 0;
	i = 0;
	while (i < size)
	{
		if (a->guard->next->index > pivot_right)
		{
			//printf("large\n");
			ra(a);
			large_count++;
		}
		else if (a->guard->next->index > pivot_left)
		{
			//printf("medium\n");
			pb(a, b);
			rb(b);
			medium_count++;
		}
		else
		{
			//printf("small\n");
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
	print_stacks(a, b);
	//printf("<<< partition_for_stack_a\n");
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

void	partition(t_stack *a, t_stack *b)
{
	partition_for_a(a, b, a->size, a->size - 1);
}
