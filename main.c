/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:04:22 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/09 00:48:42 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **argv)
{
	t_list	*stack_a;

	if (argc == 1 || !is_valid_arg(--argc, ++argv))
		print_error();
	stack_a = stack_init(argc, argv);
	return (0);
}

__attribute__((destructor)) static void destructor()
{
	system("leaks -q push_swap");
}
