/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_arg_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:55:53 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 08:05:58 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

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
			if (ft_issign(*str))
				str++;
			if (!ft_isdigit(*str))
				return (false);
			while (ft_isdigit(*str))
				str++;
			if (!*str)
				break ;
			if (*str != ' ' || !ft_isdigsig(*(str + 1)))
				return (false);
			str++;
		}
		argv++;
	}
	return (true);
}
