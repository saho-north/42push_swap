/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:21:12 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/15 22:35:26 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_nord_to_stack(int num, t_stack *stack)
{
	t_nord	*node;

	node = (t_nord *)malloc(sizeof(t_nord));
	if (!node)
		free_stack_with_error(stack);
	node->next = stack->guard_nord;
	node->prev = stack->guard_nord->prev;
	node->value = num;
	stack->guard_nord->prev->next = node;
	stack->guard_nord->prev = node;
	stack->size++;
}

static void	check_if_duplicate(int num, t_stack *stack)
{
	t_nord	*node;

	node = stack->guard_nord->next;
	while (node && node != stack->guard_nord)
	{
		if (node->value == num)
			free_stack_with_error(stack);
		node = node->next;
	}
}

t_stack	*parse_input(int argc, const char **argv)
{
	t_stack		*stack;
	const char	*str;
	const char	*endpos;
	long		num;

	stack = create_empty_stack();
	while (argc--)
	{
		str = *argv;
		while (*str)
		{
			num = ft_strtol(str, &endpos);
			if (num < INT_MIN || INT_MAX < num)
				free_stack_with_error(stack);
			check_if_duplicate((int)num, stack);
			push_nord_to_stack((int)num, stack);
			str = endpos;
		}
		argv++;
	}
	return (stack);
}
