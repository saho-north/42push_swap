/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 01:26:27 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/13 15:48:17 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_three(int first, int second, int third)
{
	return (first < second && second < third && first < third);
}

void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->guard_nord->next->value;
	second = stack_a->guard_nord->next->next->value;
	third = stack_a->guard_nord->prev->value;
	while (!is_sorted_three(first, second, third))
	{
		if (first > second && second < third && first > third)
			ra(stack_a);
		else if (first < second && second > third && first > third)
			rra(stack_a);
		else
			sa(stack_a);
		first = stack_a->guard_nord->next->value;
		second = stack_a->guard_nord->next->next->value;
		third = stack_a->guard_nord->prev->value;
	}
}

void	sort_small(t_stack *stack)
{
	int	size;

	size = stack->size;
	if (size == 1)
		return ;
	else if (size == 2)
	{
		sa(stack);
		return ;
	}
	else if (size == 3)
	{
		sort_three(stack);
	}
}

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	t_nord	*guard_node;
	int		pivot;

	if (stack_a->size <= 3)
		return (sort(stack_a));
	guard_node = stack_a->guard_nord;
	pivot = find_pivot(stack_a);
	while (stack_a->size > 3)
	{
		if (guard_node->next->value < pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a->size;
	if (size == 1)
		return ;
	else if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
		sort_large(stack_a, stack_b);
}
