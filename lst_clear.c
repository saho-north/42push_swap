/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:03:19 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/10 15:18:36 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_clear(t_list **lst)
{
	t_list	*tmp;
	t_list	*next;
	bool	is_sentinel;

	if (!lst)
		return ;
	is_sentinel = false;
	tmp = (*lst)->next;
	while (tmp && !is_sentinel)
	{
		if (tmp->is_sentinel)
			is_sentinel = true;
		else
			next = tmp->next;
		free(tmp);
		if (!is_sentinel)
			tmp = next;
	}
	*lst = NULL;
}
