/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:12:30 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/09 02:44:33 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	convert_num(const char *str, bool is_negative)
{
	long long	ov_div;
	long long	ov_mod;
	long long	num;

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
				return (-1);
			else
				return (0);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	if (is_negative)
		num *= -1;
	return (num);
}

int	str_to_int(const char *str, t_list **head)
{
	long long	num;
	bool		is_negative;

	is_negative = false;
	if (*str == ' ')
		str++;
	if (*str == '-')
	{
		is_negative = true;
		str++;
	}
	num = convert_num(str, is_negative);
	if (num < INT_MIN || INT_MAX < num)
	{
		lst_clear(head);
		print_error();
	}
	return ((int)num);
}
