/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:55:53 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/10 16:44:21 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_arg(int argc, const char **argv)
{
	const char	*str;

	while (argc--)
	{
		str = *argv;
		if (!ft_strlen(str))
			return (false);
		while (*str)
		{
			if (*str == ' ')
				str++;
			if (*str && *str == '-')
				str++;
			if (*str && !ft_isdigit(*str))
				return (false);
			while (*str && ft_isdigit(*str))
				str++;
			if (*str && *str != ' ')
				return (false);
		}
		argv++;
	}
	return (true);
}
