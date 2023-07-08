/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:14:05 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/09 02:48:26 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_init(int argc, char **argv)
{
	t_list	**head;
	t_list	*node;
	int		i;
	int		j;

	head = NULL;
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			node = lst_new(str_to_int(argv[i][j], head), head);
			if (argv[i][j] == ' ')
				j++;
			if (argv[i][j] && argv[i][j] == '-')
				j++;
			while (argv[i][j] && ft_isdigit(argv[i][j]))
				j++;
		}
		i++;
	}
	return (*head);
}
