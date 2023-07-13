/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_empty_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:46:06 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/13 15:48:10 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_nord	*create_guard_nord(void)
{
	t_nord	*guard_nord;

	guard_nord = (t_nord *)malloc(sizeof(t_nord));
	if (!guard_nord)
		return (NULL);
	guard_nord->next = guard_nord;
	guard_nord->prev = guard_nord;
	guard_nord->value = 0;
	guard_nord->is_guard_nord = true;
	guard_nord->is_pivot = false;
	return (guard_nord);
}

t_stack	*create_empty_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit_with_print_error();
	stack->guard_nord = create_guard_nord();
	if (!stack->guard_nord)
	{
		free(stack);
		exit_with_print_error();
	}
	stack->size = 0;
	return (stack);
}
