

#include "push_swap.h"

static bool	is_sorted(t_stack *stack)
{
	t_node	*guard;
	t_node	*node;

	guard = stack->guard;
	node = guard->next;
	while (node != guard && node->next != guard)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}

static int	get_pivot(t_stack *stack, int size)
{
	t_node	*node;
	int		i;

	node = stack->guard->next;
	i = 0;
	while (i < size / 2)
	{
		node = node->next;
		i++;
	}
	return (node->value);
}

/*
4. aの末尾へ小さい順に数字を挿入し、ソート済み扱いにしていく
 */

void	push_sorted_nodes(t_stack *a, t_stack *b)
{
	t_node	*guard;

	guard = b->guard;
	sort_small(b, a, STACK_B);
	while (b->size > 0)
	{
		guard->next->is_sorted = true;
		pa(a, b);
		ra(a);
	}
}

/*
3. bが分割できなくなるまで、bの数値を大小で分け、aにpushする
4. 残ったbの数値を小さい順にaの末尾へ移動する
5. aをbへpushし、bの分割を繰り返す
 */
void	partition(t_stack *a, t_stack *b)
{
	int	pivot;
	int	moved;
	int	size;
	int	i;

	size = b->size;
	if (size <= 3)
	{
		push_sorted_nodes(a, b);
		return ;
	}
	pivot = get_pivot(b, size);
	moved = 0;
	i = 0;
	while (i < size)
	{
		if (b->guard->next->value < pivot)
			rb(b);
		else
		{
			pa(a, b);
			moved++;
		}
		i++;
	}
	partition(a, b);
	while (moved > 0)
	{
		if (a->guard->is_sorted == false)
			pb(a, b);
		moved--;
	}
	partition(a, b);
}

/*
1. 初期状態。aに数値がある
2. aの数値を大小で分け、bにpushする
*/
void	quicksort(t_stack *a, t_stack *b, int size)
{
	t_node	*guard;
	int		pivot;
	int		leftover;
	int		i;

	if (b->size == 0 && is_sorted(a))
		return ;
	guard = a->guard;
	pivot = get_pivot(a, size);
	leftover = 0;
	i = 0;
	while (i < size && !guard->next->is_sorted)
	{
		printf("\n(%d/%d) value: %d, pivot:%d\n", i + 1, size,
				guard->next->value, pivot);
		if (guard->next->value < pivot)
		{
			pb(a, b);
		}
		else
		{
			ra(a);
			leftover++;
		}
		i++;
	}
	printf("leftover: %d\n", leftover);
	partition(a, b);
	// i = 0;
	// while (i < leftover)
	// {
	// 	rra(a);
	// 	i++;
	// }
	// quicksort(a, b, leftover);
}

void	sort(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	print_stacks(a, b);
	if (size < 7)
	{
		if (b->size == 0 && is_sorted(a))
			return ;
		else
			sort_small(a, b, STACK_A);
	}
	else
		quicksort(a, b, a->size);
	print_stacks(a, b);
}
