/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:21:12 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 01:15:25 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_common.h"

static void	push_node_to_stack(int num, t_stack *stack)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		free_stack_with_print_error(stack);
	node->next = stack->guard;
	node->prev = stack->guard->prev;
	node->value = num;
	stack->guard->prev->next = node;
	stack->guard->prev = node;
	stack->size++;
}

static void	check_if_duplicate(int num, t_stack *stack)
{
	t_node	*node;

	node = stack->guard->next;
	while (node && node != stack->guard)
	{
		if (node->value == num)
			free_stack_with_print_error(stack);
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
				free_stack_with_print_error(stack);
			check_if_duplicate((int)num, stack);
			push_node_to_stack((int)num, stack);
			str = endpos;
		}
		argv++;
	}
	return (stack);
}
