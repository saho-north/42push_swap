/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 01:26:27 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/15 13:56:17 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(t_stack *stack)
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

void	quicksort_b(t_stack *stack_a, t_stack *stack_b)
{
	t_nord	*guard_node;
	int		pivot;
	int		size;

	printf("\nquicksort for b\n");
	print_stacks(stack_a, stack_b);
	size = stack_b->size;
	if (size <= 3)
	{
		sort_small_b(stack_b);
		while (stack_b->size > 0)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		return ;
	}
	guard_node = stack_b->guard_nord;
	pivot = get_pivot(stack_b);
	while (size > 0 && stack_b->size > 3)
	{
		printf("\npivot = %d size(b) = %d\n", pivot, size);
		printf("current = %d\n", guard_node->next->value);
		printf("Before : \n");
		print_stacks(stack_a, stack_b);
		printf("After : \n");
		if (guard_node->next->value > pivot)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
		size--;
	}
	quicksort_b(stack_a, stack_b);
}

void	quicksort_a(t_stack *stack_a, t_stack *stack_b)
{
	t_nord	*guard_node;
	int		pivot;
	int		size;

	printf("\nquicksort for a\n");
	size = stack_a->size;
	if (size <= 3)
		return (sort(stack_a, stack_b));
	guard_node = stack_a->guard_nord;
	pivot = get_pivot(stack_a);
	while (size > 0)
	{
		printf("\npivot = %d size(a) = %d\n", pivot, size);
		printf("current = %d\n", guard_node->next->value);
		printf("Before : \n");
		print_stacks(stack_a, stack_b);
		printf("After : \n");
		if (guard_node->next->value < pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		size--;
	}
}

void	quicksort(t_stack *stack_a, t_stack *stack_b)

{
	// まず最初にstack_aの中でpivotを決めて、それより小さいものをstack_bに移動させる
	// その後、stack_bの中でpivotを決めて、それより大きいものをstack_aに移動させる
	// この操作を繰り返す
	quicksort_a(stack_a, stack_b);
	quicksort_b(stack_a, stack_b);
}
