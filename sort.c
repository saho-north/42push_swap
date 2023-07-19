

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
	int		size;
	int		i;

	node = stack->guard->next;
	size = stack->size;
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

	printf("push_sorted_nodes\n");
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
	printf("pivot: %d\n", pivot);
	tmp_in_a = 0;
	i = 0;
	while (i < size)
	{
		if (b->guard->next->value <= pivot)
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
		printf("\n>>> partition\n");
		print_stacks(a, b);
		partition(a, b);
		printf("<<< after partition\n");
		print_stacks(a, b);
	}
	if (tmp_in_a > 0)
	{
		printf("\n>>> refil\n");
		printf("tmp_in_a: %d\n", tmp_in_a);
		print_stacks(a, b);
		printf("<<< after refil\n");
		print_stacks(a, b);
		refil_stack(a, b, tmp_in_a);
		printf("\n>>> partition\n");
		print_stacks(a, b);
		partition(a, b);
		printf("<<< after partition\n");
		print_stacks(a, b);
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

	printf("\n>>> initial partition\n");
	print_stacks(a, b);
	guard = a->guard;
	size = a->size;
	pivot = get_pivot(a);
	printf("pivot: %d\n", pivot);
	i = 0;
	while (i < size)
	{
		if (guard->next->value <= pivot)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	printf("<<< after initial partition\n");
	print_stacks(a, b);
	partition_and_refill(a, b, a->size);
}

void	sort(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	print_stacks(a, b);
	if (b->size == 0 && is_sorted(a))
		return ;
	if (size < 7)
	{
		sort_small(a, b, STACK_A);
	}
	else
		initial_partition(a, b);
	print_stacks(a, b);
}
