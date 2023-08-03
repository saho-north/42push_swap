/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:58:28 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 04:30:09 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	ra_bonus(t_stack *a)
{
	rotate(a);
}

void	rb_bonus(t_stack *b)
{
	rotate(b);
}

void	rr_bonus(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}
