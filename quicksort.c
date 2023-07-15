

// #include "push_swap.h"

// int	get_pivot(t_stack *stack)
// {
// 	t_nord	*node;
// 	int		size;
// 	int		i;

// 	node = stack->guard_nord->next;
// 	size = stack->size;
// 	i = 0;
// 	while (i < size / 2)
// 	{
// 		node = node->next;
// 		i++;
// 	}
// 	return (node->value);
// }

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

// void	quicksort_a(t_stack *a, t_stack *b)
// {
// 	t_nord	*guard_node;
// 	int		pivot;
// 	int		size;

// 	printf("\nquicksort for a\n");
// 	size = a->size;
// 	if (size <= 3)
// 		return (sort(a, b));
// 	guard_node = a->guard_nord;
// 	pivot = get_pivot(a);
// 	while (size > 0)
// 	{
// 		printf("\npivot = %d size(a) = %d\n", pivot, size);
// 		printf("current = %d\n", guard_node->next->value);
// 		printf("Before : \n");
// 		print_stacks(a, b);
// 		printf("After : \n");
// 		if (guard_node->next->value < pivot)
// 			pb(a, b);
// 		else
// 			ra(a);
// 		size--;
// 	}
// }

// void	quicksort(t_stack *a, t_stack *b)

// {
// 	まず最初にaの中でpivotを決めて、それより小さいものをbに移動させる
// 	その後、bの中でpivotを決めて、それより大きいものをaに移動させる
// 	この操作を繰り返す
// 	quicksort_a(a, b);
// 	quicksort_b(a, b);
// }
