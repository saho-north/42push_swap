/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 03:31:28 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/21 04:57:23 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_possible_pivots(int possible_pivots[])
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < 2)
	{
		j = i + 1;
		while (j < 3)
		{
			if (possible_pivots[i] > possible_pivots[j])
			{
				tmp = possible_pivots[i];
				possible_pivots[i] = possible_pivots[j];
				possible_pivots[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (possible_pivots[1]);
}

int	get_pivot(t_stack *stack, int size)
{
	t_node	*node;
	int		possible_pivots[3];
	int		i;

	node = stack->guard->next;
	possible_pivots[0] = node->value;
	i = 0;
	while (i < size - 1)
	{
		if (i == size / 2)
			possible_pivots[1] = node->value;
		node = node->next;
		i++;
	}
	possible_pivots[2] = node->value;
	return (check_possible_pivots(possible_pivots));
}
