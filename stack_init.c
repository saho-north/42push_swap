/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:14:05 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/09 03:58:36 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_dummy(void)
{
	t_list	*dummy;

	dummy = (t_list *)malloc(sizeof(t_list));
	if (!dummy)
		print_error();
	dummy->next = dummy;
	dummy->prev = dummy;
	dummy->value = 0;
	dummy->is_dummy = true;
	return (dummy);
}

t_list	*stack_init(int argc, const char **argv)
{
	t_list	*dummy;
	t_list	*node;
	int		i;
	int		j;

	dummy = create_dummy();
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			node = lst_new(str_to_int(&argv[i][j], &dummy), &dummy);
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
	printf("dummy->next->value = %d\n", dummy->next->value);
	return (dummy);
}
