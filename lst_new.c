/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:05:15 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/09 01:13:57 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(int value, t_list **head)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		error_free_exit(*head);
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	if (*head)
	{
		node->prev = (*head)->prev;
		node->next = *head;
		(*head)->prev = node;
	}
	else
	{
		node->prev = node;
		node->next = node;
		*head = node;
	}
	return (node);
}
