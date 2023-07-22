/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:52:33 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/23 02:21:59 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		partition(t_stack *a, t_stack *b, int size_a, int size_b);

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

void	partition_for_stack_b(t_stack *a, t_stack *b, int size)
{
	t_node	*guard;
	int		pivot;
	int		size_a;
	int		rb_count;
	int		i;

	//printf("\n>>> partition_for_stack_b\n");
	print_stacks(a, b);
	guard = b->guard;
	if (size < 3 || b->size <= 3)
	{
		sort_small(b, a, size, STACK_B);
		while (b->size > 0 && size > 0)
		{
			pa(a, b);
			size--;
		}
		return ;
	}
	pivot = get_pivot(b, size);
	size_a = 0;
	i = 0;
	while (i < size)
	{
		if (guard->next->value > pivot)
		{
			pa(a, b);
			size_a++;
		}
		else
		{
			rb(b);
		}
		i++;
	}
	rb_count = size - size_a;
	while (rb_count > 0)
	{
		rrb(b);
		rb_count--;
	}
	//printf("size_a = %d, size_b = %d\n", size_a, size - size_a);
	print_stacks(a, b);
	//printf("<<< partition_for_stack_b\n");
	partition(a, b, size_a, size - size_a);
}

void	partition_for_stack_a(t_stack *a, t_stack *b, int size)
{
	t_node	*guard;
	int		pivot;
	int		size_b;
	int		i;
	int		ra_count;

	//printf("\n>>> partition_for_stack_a\n");
	print_stacks(a, b);
	guard = a->guard;
	if (size < 3 || a->size <= 3)
	{
		sort_small(a, b, size, STACK_A);
		return ;
	}
	pivot = get_pivot(a, size);
	size_b = 0;
	i = 0;
	while (i < size)
	{
		if (guard->next->value < pivot)
		{
			pb(a, b);
			size_b++;
		}
		else
		{
			ra(a);
		}
		i++;
	}
	ra_count = size - size_b;
	while (a->size != size - size_b && ra_count > 0)
	{
		rra(a);
		ra_count--;
	}
	//printf("size_a = %d, size_b = %d\n", size - size_b, size_b);
	print_stacks(a, b);
	//printf("<<< partition_for_stack_a\n");
	partition(a, b, size - size_b, size_b);
}

void	partition(t_stack *a, t_stack *b, int size_a, int size_b)
{
	if (size_a > 0)
	{
		partition_for_stack_a(a, b, size_a);
	}
	if (size_b > 0)
	{
		partition_for_stack_b(a, b, size_b);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (b->size == 0 && is_sorted(a))
		return ;
	if (size < 7)
	{
		sort_small(a, b, size, STACK_A);
	}
	else
		partition(a, b, size, 0);
}
