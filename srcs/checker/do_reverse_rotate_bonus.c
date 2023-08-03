/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:20:44 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 04:30:09 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	rra_bonus(t_stack *a)
{
	reverse_rotate(a);
}

void	rrb_bonus(t_stack *b)
{
	reverse_rotate(b);
}

void	rrr_bonus(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
