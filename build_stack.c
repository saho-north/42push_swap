/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:14:05 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/10 13:33:40 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_sentinel(void)
{
	t_list	*sentinel;

	sentinel = (t_list *)malloc(sizeof(t_list));
	if (!sentinel)
		exit_with_error();
	sentinel->next = sentinel;
	sentinel->prev = sentinel;
	sentinel->value = 0;
	sentinel->is_sentinel = true;
	return (sentinel);
}

t_list	*build_stack(int argc, const char **argv)
{
	t_list		*sentinel;
	t_list		*node;
	int			i;
	int			j;
	long long	num;

	sentinel = create_sentinel();
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			num = ft_strtoll(&argv[i][j]);
			if (num < INT_MIN || INT_MAX < num)
			{
				lst_clear(&sentinel);
				exit_with_error();
			}
			node = new_node(num, &sentinel);
			printf("node->value = %d\n", node->value);
			if (argv[i][j] == ' ')
				j++;
			if (argv[i][j] && argv[i][j] == '-')
				j++;
			while (argv[i][j] && ft_isdigit(argv[i][j]))
				j++;
		}
		i++;
	}
	printf("sentinel->next->value = %d\n", sentinel->next->value);
	return (sentinel);
}
