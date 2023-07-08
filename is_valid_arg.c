/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:55:53 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/09 03:10:00 by sakitaha         ###   ########.fr       */
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
			printf("argv[%d][%d] = %c\n", i, j, argv[i][j]);
			if (argv[i][j] == ' ')
				j++;
			if (argv[i][j] && argv[i][j] == '-')
				j++;
			if (argv[i][j] && !ft_isdigit(argv[i][j]))
				return (false);
			while (argv[i][j] && ft_isdigit(argv[i][j]))
				j++;
			if (argv[i][j] && argv[i][j] != ' ')
				return (false);
		}
		i++;
	}
	return (true);
}
