/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:04:22 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/20 02:12:05 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1 || !is_valid_arg(--argc, ++argv))
		exit_with_print_error();
	a = parse_input(argc, argv);
	if (!a)
		exit_with_print_error();
	b = create_empty_stack();
	if (!b)
		free_stack_with_error(a);
	sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
