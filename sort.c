

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

static int	get_pivot(t_stack *stack)
{
	t_node	*node;
	int		count_to_middle;
	int		first;
	int		middle;
	int		last;

	node = stack->guard->next;
	count_to_middle = stack->size / 2;
	while (count_to_middle--)
		node = node->next;
	first = stack->guard->next->value;
	middle = node->value;
	last = stack->guard->prev->value;
	if (first < middle && middle < last)
		return (middle);
	else if (last < middle && middle < first)
		return (middle);
	else if (first < last && last < middle)
		return (last);
	else if (middle < last && last < first)
		return (last);
	else
		return (first);
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

void	refil_stack(t_stack *a, t_stack *b, int tmp_in_a)
{
	int	i;

	i = 0;
	while (i < tmp_in_a)
	{
		if (a->guard->next->is_sorted == false)
			pb(a, b);
		i++;
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
	int	size;
	int	tmp_in_a;
	int	i;

	if (b->size <= 3)
	{
		push_sorted_nodes(a, b);
		return ;
	}
	size = b->size;
	pivot = get_pivot(b);
	tmp_in_a = 0;
	i = 0;
	while (i < size)
	{
		if (b->guard->next->value < pivot)
			rb(b);
		else
		{
			pa(a, b);
			tmp_in_a++;
		}
		i++;
	}
	partition_and_refill(a, b, tmp_in_a);
}

void	partition_and_refill(t_stack *a, t_stack *b, int tmp_in_a)
{
	if (b->size > 0)
	{
		partition(a, b);
	}
	if (tmp_in_a > 0)
	{
		refil_stack(a, b, tmp_in_a);
	}
	if (b->size > 0)
	{
		partition(a, b);
	}
}

/*
1. 初期状態。aに数値がある
2. aの数値を大小で分け、bにpushする
*/
void	initial_partition(t_stack *a, t_stack *b)
{
	t_node	*guard;
	int		size;
	int		pivot;
	int		i;

	guard = a->guard;
	size = a->size;
	pivot = get_pivot(a);
	i = 0;
	while (i < size)
	{
		if (guard->next->value <= pivot)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	partition_and_refill(a, b, a->size);
}

void	sort(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (b->size == 0 && is_sorted(a))
		return ;
	if (size < 7)
	{
		sort_small(a, b, STACK_A);
	}
	else
		initial_partition(a, b);
}
