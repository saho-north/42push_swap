/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:05:15 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/09 03:58:11 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(int value, t_list **dummy)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
	{
		lst_clear(dummy);
		print_error();
	}
	node->next = *dummy;
	node->prev = (*dummy)->prev;
	(*dummy)->prev->next = node;
	(*dummy)->prev = node;
	node->value = value;
	return (node);
}
