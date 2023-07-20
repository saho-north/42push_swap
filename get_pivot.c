/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 03:31:28 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/21 03:31:40 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_pivots(int pivots[])
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
			if (pivots[i] > pivots[j])
			{
				tmp = pivots[i];
				pivots[i] = pivots[j];
				pivots[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (pivots[1]);
}

int	get_pivot(t_stack *stack, int size)
{
	t_node	*node;
	int		pivots[3];
	int		i;
	int		j;
	int		tmp;

	node = stack->guard->next;
	pivots[0] = node->value;
	i = 0;
	while (i < size - 1)
	{
		if (i == size / 2)
			pivots[1] = node->value;
		node = node->next;
		i++;
	}
	pivots[2] = node->value;
	return (check_pivots(pivots));
}
