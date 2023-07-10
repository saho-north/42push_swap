/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:12:30 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/10 16:13:05 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	convert_num(const char *str, bool is_negative)
{
	long long	ov_div;
	long long	ov_mod;
	long long	num;

	ov_div = LLONG_MAX / 10;
	ov_mod = LLONG_MAX % 10;
	if (is_negative)
		ov_mod++;
	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (num > ov_div || (num == ov_div && (*str - '0') > ov_mod))
		{
			if (!is_negative)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	if (is_negative)
		num *= -1;
	return (num);
}

long long	ft_strtoll(const char *str)
{
	long long	num;
	bool		is_negative;

	is_negative = false;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = true;
		str++;
	}
	return (convert_num(str, is_negative));
}
