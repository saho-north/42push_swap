/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:28:36 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 04:40:17 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	pa_bonus(t_stack *a, t_stack *b)
{
	push(b, a);
}

void	pb_bonus(t_stack *a, t_stack *b)
{
	push(a, b);
}
