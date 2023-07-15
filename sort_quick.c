

#include "push_swap.h"

// void	quicksort_b(t_stack *a, t_stack *b)
// {
// 	t_nord	*guard_node;
// 	int		pivot;
// 	int		size;

// 	printf("\nquicksort for b\n");
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
// 	quicksort_b(a, b);
// }

static int	get_pivot(t_stack *stack)
{
	t_nord	*node;
	int		size;
	int		i;

	node = stack->guard_nord->next;
	size = stack->size;
	i = 0;
	while (i < size / 2)
	{
		node = node->next;
		i++;
	}
	return (node->value);
}

void	quicksort(t_stack *a, t_stack *b, int size, bool is_stack_a)
{
	t_nord	*guard_node;
	int		pivot;
	int		size;
	int		moved;
	int		i;

	printf("\nquicksort for a\n");
	guard_node = a->guard_nord;
	size = a->size;
	moved = 0;
	if (size <= 3)
	{
		sort_small(a, b, is_stack_a);
	}
	pivot = get_pivot(a);
	i = 0;
	while (i < size && a->size > 3)
	{
		printf("\npivot = %d size(a) = %d\n", pivot, size);
		printf("current = %d\n", guard_node->next->value);
		printf("Before : \n");
		print_stacks(a, b);
		printf("After : \n");
		if (guard_node->next->value < pivot)
		{
			if (is_stack_a)
				pb(a, b);
			else
				pa(a, b);
		}
		else
		{
			if (is_stack_a)
				ra(a);
			else
				rb(b);
		}
		i++;
	}
}

static bool	is_sorted(t_stack *stack)
{
	t_nord	*guard_node;
	t_nord	*node;

	guard_node = stack->guard_nord;
	node = guard_node->next;
	while (node != guard_node && node->next != guard_node)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}

void	sort(t_stack *a, t_stack *b)
{
	t_nord	*node;
	int		size;

	size = a->size;
	if (b->size == 0 && is_sorted(a))
		return ;
	else if (size == 1)
		return ;
	else if (size == 2)
	{
		printf("sort_two_a\n");
		node = a->guard_nord->next;
		if (node->value > node->next->value)
			sa(a);
	}
	else if (size == 3)
		sort_three_a(a);
	else if (size < 7)
		sort_six_or_less(a, b);
	else
		quicksort(a, b);
}

/*
ダブルリンクドリストでのクイックソートの一例は以下のようになるでしょう。ただし、この疑似コードは単純化されており、エラーチェックや特殊なケースの処理は省略されています。また、概念的に理解しやすいように説明を優先しています。

```plaintext
1. 関数 quickSort(stackA, stackB)：
2.    if stackA が 1つの要素だけなら、
3.        return
4.    pivot を選び、それを stackB に push
5.    stackA の要素を全て調べる:
6.        if 要素が pivot より小さければ stackB に push
7.        それ以外の場合は、そのまま stackA に残す
8.    stackB の要素を全て stackA に push（ここで stackA はソート済みの部分と未ソートの部分に分かれる）
9.    quickSort(ソート済みの部分, stackB)
10.   quickSort(未ソートの部分, stackB)
```

このアルゴリズムはクイックソートの基本的なアイデアに基づいていますが、スタック（ここではダブルリンクドリストを使用）というデータ構造を使用しているため、一部の操作が特有のものになっています。具体的には、pivot を選択した後にそれを一時的に stackB に移動させ、そこから比較を行っています（ステップ 4 と 5）。また、要素を push と pop を行うことで、pivot を中心に要素を分割しています（ステップ 6 と 7）。

そして最終的に、ステップ 8 でソートされた部分と未ソートの部分に stackA を分割します。その後、再帰的にこれらの部分に対して同じ手順を繰り返すことで、全体をソートしています（ステップ 9 と 10）。


もちろんです。まず、私たちは `quickSort` 関数をステップ 1 から 8 まで進めて、pivot を中心に要素を分割しています。ここで、`stackA` にはpivotより大きい要素（未ソートの部分）とpivot以下の要素（ソート済みの部分）が含まれています。

次に、ステップ 9 と 10 でそれぞれの部分に再度 `quickSort` を適用します。これにより、さらに小さな部分に分割されてソートが進行します。これは、再帰的にこのプロセスを繰り返すことで全体をソートしていく、というクイックソートの基本的なアイデアです。

ただし、このプロセスを実際に実装する際には、どの部分がソート済みで、どの部分が未ソートであるかを正確に追跡する必要があります。一般的には、これは `stackA` 内の特定の位置（インデックス）を記録することで行います。たとえば、`stackA` の中心（または他の適当な位置）をpivotとして選び、その位置を記録しておきます。そして、それを基準に `quickSort` 関数を適用する部分を選びます。

具体的には以下のようなプロセスになるかと思います：

```plaintext
1.   quickSort(ソート済みの部分, stackB) について：
     pivotを中心に左側にある要素（pivot以下）がソート済みの部分になります。
     quickSort関数を再度呼び出し、この部分に対してソートを行います。
     再帰呼び出しにより、これらの要素がさらに分割・ソートされていきます。

2.   quickSort(未ソートの部分, stackB) について：
     pivotを中心に右側にある要素（pivotより大きい）が未ソートの部分になります。
     quickSort関数を再度呼び出し、この部分に対してソートを行います。
     再帰呼び出しにより、これらの要素がさらに分割・ソートされていきます。
```

このプロセスは、全ての要素がソートされるまで続けられます。その結果、`stackA` にはソートされた要素が格納されます。
あなたのコードを見ると、基本的なクイックソートのアイディアが適切に実装されているように見えます。pivotを選択し、それを基準に値を分割し、それぞれの部分に対して再帰的にクイックソートを適用しています。しかし、以下の点について考慮する必要があると思われます：

1. **Base Case of Recursion**：再帰の基本ケース（終了条件）を設定することは重要です。あなたのコードでは、スタックのサイズが3以下の場合にソートを終了するようになっていますが、その後、`pa(a,
		b)`と`ra(a)`の操作を行っています。これはスタックBからスタックAへ要素を移動し、スタックAを回転させる操作ですが、この操作が全ての再帰ステップで必要かどうかは再考するべきかもしれません。また、サイズが1の場合にも終了条件を設けると良いでしょう。

2. **Selection of Pivot**：あなたのコードでは、ピボットとしてスタックの中央の値を選択しています。これは妥当な選択ですが、クイックソートのパフォーマンスは選択されたpivotに大きく依存します。そのため、より良いpivotの選択方法を考えることも考慮に入れるべきです。

3. **Sorted Part Management**：クイックソートは、データを「ソート済み」部分と「未ソート」部分に分割することで動作します。あなたのコードでは、それぞれの部分に対して`quicksort_a`および`quicksort_b`が呼び出されます。しかし、これらの関数が呼び出される際に、それぞれがどの部分（ソー��済みまたは未ソート��を操作して���るのか、また、それがどのように更新されていくのかを明確に管理することが重要です。

4. **Debugging Prints**：デ��ッグ出力はコードの理解に非常に役立ち��すが、完成し��コ��ドでは不要な出力は避けるべきです。デバッグが完了したら、これらの出力は削除またはコメントアウトをおすすめします。

これらの点を考慮に入れて、あなたのコードを改善してみてください。


 */
