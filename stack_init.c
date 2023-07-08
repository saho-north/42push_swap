/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:14:05 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/09 01:07:33 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_init(int argc, char **argv)
{
	t_list		**head;
	t_list		*node;
	int			i;
	int			j;
	long long	value;

	head = NULL;
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			value = ft_atol(argv[i][j]);
			if (value < INT_MIN || INT_MAX < value)
				print_error_free(head);
			node = lst_new((int)value, head);
			(*head)->prev = node;
			(*head) = node;
			while (argv[i][j] && (argv[i][j] == '-' || ft_isdigit(argv[i][j])))
				j++;
		}
		i++;
	}
}
