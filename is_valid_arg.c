/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:55:53 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/12 01:23:03 by sakitaha         ###   ########.fr       */
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
			if (*str == '-')
				str++;
			if (!*str || !ft_isdigit(*str))
				return (false);
			while (*str && ft_isdigit(*str))
				str++;
			if (!*str)
				break ;
			if (*str != ' ' || (!ft_isdigit(*(str + 1)) && *(str + 1) != '-'))
				return (false);
			str++;
		}
		argv++;
	}
	return (true);
}
