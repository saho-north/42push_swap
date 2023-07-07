/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:04:22 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/07 16:38:31 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_arg(int argc, const char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (!ft_isdigit(*argv[i]))
				return (false);
			while (argv[i][j] && ft_isdigit(argv[i][j]))
				j++;
			if (!argv[i][j])
				break ;
			if (argv[i][j] != ' ')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	main(int argc, const char **argv)
{
	if (argc == 1 || !is_valid_arg(--argc, ++argv))
		error();
	stack_init(argc, argv);
	return (0);
}
