/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:55:53 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/14 18:28:53 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_common.h"

static bool	is_valid_arg_end(const char *current_str, const char *next_str)
{
	size_t	current_str_len;

	current_str_len = ft_strlen(current_str);
	if (ft_isdigit(current_str[current_str_len - 1]))
		return (true);
	if (ft_isspace(current_str[current_str_len - 1]) && next_str)
	{
		if (ft_isdigsig(*next_str))
			return (true);
	}
	return (false);
}

static bool	has_valid_numbers_after_sign(const char *str)
{
	while (*str >= '0' && *str <= '9')
	{
		if (*str >= '1' && *str <= '9')
		{
			return (true);
		}
		str++;
	}
	return (false);
}

static bool	is_valid_current_str(const char *str)
{
	if (ft_isspace(*str))
		str++;
	while (*str)
	{
		if (ft_issign(*str))
		{
			str++;
			if (!has_valid_numbers_after_sign(str))
				return (false);
		}
		if (!ft_isdigit(*str))
			return (false);
		while (ft_isdigit(*str))
			str++;
		if (!*str || (*str == ' ' && !*(str + 1)))
			break ;
		if (*str != ' ' || !ft_isdigsig(*(str + 1)))
			return (false);
		str++;
	}
	return (true);
}

static bool	is_valid_arg_start(int arg_index, const char **argv)
{
	const char	*current_str;
	const char	*prev_str;
	size_t		current_str_len;

	current_str = argv[arg_index];
	current_str_len = ft_strlen(current_str);
	if (!current_str_len)
		return (false);
	if (ft_isdigsig(*current_str))
		return (true);
	if (ft_isspace(*current_str) && current_str_len > 1 && arg_index > 0)
	{
		if (!ft_isdigsig(*(current_str + 1)))
			return (false);
		prev_str = argv[arg_index - 1];
		if (ft_isdigit(prev_str[ft_strlen(prev_str) - 1]))
			return (true);
	}
	return (false);
}

bool	is_valid_arg(int argc, const char **argv)
{
	const char	*next_str;
	int			arg_index;

	arg_index = 0;
	while (arg_index < argc)
	{
		if (!is_valid_arg_start(arg_index, argv))
			return (false);
		if (!is_valid_current_str(argv[arg_index]))
			return (false);
		if (arg_index + 1 < argc)
			next_str = argv[arg_index + 1];
		else
			next_str = NULL;
		if (!is_valid_arg_end(argv[arg_index], next_str))
			return (false);
		arg_index++;
	}
	return (true);
}
