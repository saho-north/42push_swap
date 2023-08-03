/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:57:48 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/03 23:52:09 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	multi_rrr(t_stack *a, t_stack *b, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		rrr(a, b);
		i++;
	}
}
