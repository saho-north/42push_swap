/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:06:49 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/02 14:45:01 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	convert_num(const char *str, const char **endpos, bool is_negative)
{
	long	num;
	long	ov_div;
	long	ov_mod;

	ov_div = LONG_MAX / 10;
	ov_mod = LONG_MAX % 10;
	if (is_negative)
		ov_mod++;
	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (num > ov_div || (num == ov_div && (*str - '0') > ov_mod))
		{
			if (!is_negative)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	*endpos = str;
	if (is_negative)
		num *= -1;
	return (num);
}

long	ft_strtol(const char *str, const char **endpos)
{
	bool	is_negative;

	is_negative = false;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = true;
		str++;
	}
	return (convert_num(str, endpos, is_negative));
}
