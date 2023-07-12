/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:35:22 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/13 00:11:57 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_nord	*current;

	current = stack->guard_nord->next;
	while (current != stack->guard_nord)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n----------------------------\n");
}
