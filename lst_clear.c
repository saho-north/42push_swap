/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:03:19 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/09 04:05:36 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_clear(t_list **lst)
{
	t_list	*tmp;
	t_list	*next;
	bool	is_dummy;

	if (!lst)
		return ;
	is_dummy = false;
	tmp = (*lst)->next;
	while (tmp && !is_dummy)
	{
		if (tmp->is_dummy)
			is_dummy = true;
		else
			next = tmp->next;
		free(tmp);
		if (!is_dummy)
			tmp = next;
	}
	*lst = NULL;
}
