
// #include "push_swap.h"

// // void	merge_sort_b(t_stack *a, t_stack *b)
// // {
// // 	t_nord	*guard_node;
// // 	int		pivot;
// // 	int		size;

// // 	printf("\nmerge_sort for b\n");
// // 	print_stacks(a, b);
// // 	size = b->size;
// // 	if (size <= 3)
// // 	{
// // 		sort_small_b(b);
// // 		while (b->size > 0)
// // 		{
// // 			pa(a, b);
// // 			ra(a);
// // 		}
// // 		return ;
// // 	}
// // 	guard_node = b->guard_nord;
// // 	pivot = get_pivot(b);
// // 	while (size > 0 && b->size > 3)
// // 	{
// // 		printf("\npivot = %d size(b) = %d\n", pivot, size);
// // 		printf("current = %d\n", guard_node->next->value);
// // 		printf("Before : \n");
// // 		print_stacks(a, b);
// // 		printf("After : \n");
// // 		if (guard_node->next->value > pivot)
// // 			pa(a, b);
// // 		else
// // 			rb(b);
// // 		size--;
// // 	}
// // 	merge_sort_b(a, b);
// // }

//
// 	1. **分割**：スタックAの要素の半分をスタックBに移動します。この際、スタックAとスタックBにはそれぞれ半分の要素が含まれています。スタックBに移動した要素は、その後の処理でスタックAに再度移動されるため、スタックBを一時的な保存場所として使用しています。

//
// 2. **再帰的にソート**：スタックAに残った要素について、再び同じ手順（つまりスタックAの要素の半分をスタックBに移動し、スタックAを再帰的にソート）を繰り返します。これをスタックAの要素が1つになるまで行います。要素が1つだけのスタックはすでにソートされているとみなすことができます。

//
// 3. **統合**：スタックAがソートされたら、スタックBから要素をスタックAに戻します。このとき、スタックAの要素とスタックBの要素を比較しながら戻すことで、マージ（統合）とソートを同時に行います。つまり、スタックAとスタックBの先頭を見て、小さい方を新しいスタックAの要素として追加します。この操作をスタックBの要素がなくなるまで繰り返します。

// // 4. このプロセスを元のスタックAの全要素に対して繰り返します。最終的にスタックAにはソートされた要素が格納されています。

//
// 上記の手順で再帰的にマージソートを行うことができます。ただし、2つのスタックのみを用いてマージソートを実装するため、実装がやや複雑になることに注意してください。

// void	merge(t_stack *a, t_stack *b, int size_a, int size_b)
// {
// 	t_nord	*guard_a;
// 	t_nord	*guard_b;
// 	int		top_a;
// 	int		top_b;

// 	// a and b are sorted stacks. We want to merge them into a
// 	printf("\nmerge\n");
// 	guard_a = a->guard_nord;
// 	guard_b = b->guard_nord;
// 	while (size_a > 0 && size_b > 0)
// 	{
// 		top_a = guard_a->next->value;
// 		top_b = guard_b->next->value;
// 		// If the top element of a is smaller, move it to b
// 		printf("top_a = %d top_b = %d\n", top_a, top_b);
// 		if (top_a < top_b)
// 		{
// 			pa(a, b);
// 			size_b--;
// 		}
// 		else
// 		{
// 			// Move the element to a temporary stack to get to the next one
// 			pb(a, b);
// 			size_a--;
// 		}
// 	}
// 	// If there are remaining elements in b, move them to a
// 	while (size_b > 0)
// 	{
// 		printf("size_b = %d\n", size_b);
// 		pa(a, b);
// 		size_b--;
// 	}
// 	// The elements we moved to b are now on top in reverse order,
// 	// so we move them back
// 	while (size_a > 0)
// 	{
// 		printf("size_a = %d\n", size_a);
// 		pa(a, b);
// 		size_a--;
// 	}
// }

// void	split(t_stack *a, t_stack *b, int size, bool is_stack_a)
// {
// 	int	half;
// 	int	i;

// 	printf("split for %s (size %d) (half %d)\n", is_stack_a ? "a" : "b", size,
// 			size / 2);
// 	if (size <= 1)
// 		return ;
// 	half = size / 2;
// 	i = 0;
// 	while (i < half)
// 	{
// 		if (is_stack_a)
// 			pb(a, b);
// 		else
// 			pa(a, b);
// 		i++;
// 	}
// 	// Recursively sort both halves until they are of size 1
// 	split(a, b, size - half, true);
// 	split(a, b, half, false);
// 	// Now merge them back
// 	merge(a, b, size - half, half);
// }

// // starting point for the merge sort it may not be the best way to do it
// void	merge_sort(t_stack *a, t_stack *b)
// {
// 	int	size;

// 	size = a->size;
// 	printf("merge_sort for a (size %d)\n", size);
// 	split(a, b, size, true);
// }
