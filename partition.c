/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:14:21 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/31 20:47:58 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
