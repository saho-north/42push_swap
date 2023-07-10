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

void	exit_with_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	exit_with_error_and_free(t_list *ptr)
{
	lst_clear(&ptr);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
