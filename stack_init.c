/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:14:05 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/07 17:23:27 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(int argc, char **argv)
{
	t_list		**stack_a;
	t_list		*node;
	t_list		*prev;
	int			i;
	int			j;
	long long	value;

	// stack_a is a pointer to the top of the stack
	stack_a = NULL;
	// node is a pointer to the new node
	node = NULL;
	// prev is a pointer to the previous node
	prev = NULL;
	// i is the index of the argument
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			value = ft_atol(argv[i][j++]);
			if (value < INT_MIN || INT_MAX < value)
				error_free_exit(stack_a);
			node = lst_new(value, prev, NULL);
			if (!node)
				error_free_exit(stack_a);
			if (!stack_a)
				stack_a = &node;
			else
				lst_add_back(stack_a, node);
			while (argv[i][j] && ft_isdigit(argv[i][j]))
				j++;
		}
		i++;
	}
}
