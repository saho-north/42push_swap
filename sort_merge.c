/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 01:26:27 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/15 14:41:22 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	merge_sort_b(t_stack *a, t_stack *b)
// {
// 	t_nord	*guard_node;
// 	int		pivot;
// 	int		size;

// 	printf("\nmerge_sort for b\n");
// 	print_stacks(a, b);
// 	size = b->size;
// 	if (size <= 3)
// 	{
// 		sort_small_b(b);
// 		while (b->size > 0)
// 		{
// 			pa(a, b);
// 			ra(a);
// 		}
// 		return ;
// 	}
// 	guard_node = b->guard_nord;
// 	pivot = get_pivot(b);
// 	while (size > 0 && b->size > 3)
// 	{
// 		printf("\npivot = %d size(b) = %d\n", pivot, size);
// 		printf("current = %d\n", guard_node->next->value);
// 		printf("Before : \n");
// 		print_stacks(a, b);
// 		printf("After : \n");
// 		if (guard_node->next->value > pivot)
// 			pa(a, b);
// 		else
// 			rb(b);
// 		size--;
// 	}
// 	merge_sort_b(a, b);
// }

// 	1. **分割**：スタックAの要素の半分をスタックBに移動します。この際、スタックAとスタックBにはそれぞれ半分の要素が含まれています。スタックBに移動した要素は、その後の処理でスタックAに再度移動されるため、スタックBを一時的な保存場所として使用しています。

// 2. **再帰的にソート**：スタックAに残った要素について、再び同じ手順（つまりスタックAの要素の半分をスタックBに移動し、スタックAを再帰的にソート）を繰り返します。これをスタックAの要素が1つになるまで行います。要素が1つだけのスタックはすでにソートされているとみなすことができます。

// 3. **統合**：スタックAがソートされたら、スタックBから要素をスタックAに戻します。このとき、スタックAの要素とスタックBの要素を比較しながら戻すことで、マージ（統合）とソートを同時に行います。つまり、スタックAとスタックBの先頭を見て、小さい方を新しいスタックAの要素として追加します。この操作をスタックBの要素がなくなるまで繰り返します。

// 4. このプロセスを元のスタックAの全要素に対して繰り返します。最終的にスタックAにはソートされた要素が格納されています。

// 上記の手順で再帰的にマージソートを行うことができます。ただし、2つのスタックのみを用いてマージソートを実装するため、実装がやや複雑になることに注意してください。

void	split(t_stack *a, t_stack *b, int size, bool is_a)
{
	int	half;
	int	i;

	if (size <= 1)
		return ;
	half = size / 2;
	i = 0;
	while (i < half)
	{
		if (is_a)
			pb(a, b);
		else
			pa(a, b);
		i++;
	}
	// Recursively sort both halves
	split(a, b, size - half, true);
	split(b, a, half, false);
	// Now merge them back
	merge(a, b, size - half, half);
}

void	merge(t_stack *a, t_stack *b, int size_a, int size_b)
{
	t_nord	*guard_a;
	t_nord	*guard_b;
	int		top_a;
	int		top_b;

	guard_a = a->guard_nord;
	guard_b = b->guard_nord;
	// a and b are sorted stacks. We want to merge them into a
	while (size_a > 0 && size_b > 0)
	{
		top_a = guard_a->next->value;
		top_b = guard_b->next->value;
		if (top_a < top_b)
		{
			pa;
			size_b--;
		}
		else
		{
			// Move the element to a temporary stack to get to the next one
			pb;
			size_a--;
		}
	}
	// If there are remaining elements in b, move them to a
	while (size_b > 0)
	{
		pa;
		size_b--;
	}
	// The elements we moved to b are now on top in reverse order,
	// so we move them back
	while (size_a > 0)
	{
		pa;
		size_a--;
	}
}

void	merge_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	i;

	size = a->size;
	printf("merge_sort for a (size %d)\n", size);
	// 	aをソートするため、まず半分の要素をbに移動します。
	i = 0;
	while (i < size / 2)
	{
		pb(a, b);
		i++;
	}
	//sizeが元々のstackの大きさで、iの大きさでbに移ったsizeがわかっている
	printf("stack.size = %d, i = %d\n", size, i);
	merge_sort(a, b);
}

// void	tmp(t_stack *a, t_stack *b)

// {
// 	// 	1. **スタックA**をソートするため、まず半分の要素を**スタックB**に移動します。

// 	// 2. **スタックA**を再帰的にソートします。

// 	// 3. 次に、**スタックB**を再帰的にソートします。しかし、ソートされた結果は**スタックA**の上部に出てくるため、逆順になってしまいます。

// 	// 4. 最後に、**スタックA**の上部（**スタックB**から移動した要素）と**スタックA**の下部（最初に**スタックA**に残っていた要素）をマージします。

// 	merge_sort_a(a, b);
// 	merge_sort_b(a, b);
// }
