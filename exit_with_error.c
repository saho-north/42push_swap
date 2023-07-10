/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:10:56 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/09 02:56:39 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
}

void	exit_with_error(void)
{
	print_error();
	exit(EXIT_FAILURE);
}

void	free_list_and_exit_with_error(t_list *lst)
{
	free_doubly_linked_list(&lst);
	exit_with_error();
}

void	free_lists_and_exit_with_error(t_list *lst1, t_list *lst2)
{
	free_doubly_linked_list(&lst1);
	free_doubly_linked_list(&lst2);
	exit_with_error();
}
