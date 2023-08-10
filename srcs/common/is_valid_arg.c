/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:55:53 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/10 22:47:22 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_common.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

static bool	is_valid_arg_end(int i, int argc, const char **argv,
		const char *str)
{
	const char	*next_str;

	if (ft_isdigsig(*str))
		return (true);
	if (*str && !ft_isdigsig(*str))
		return (false);
	if (!argc)
		return (false);
	next_str = *argv;
	return (ft_isdigsig(*next_str));
}

static bool	is_valid_str(const char *str)
{
	while (*str)
	{
		if (ft_issign(*str))
			str++;
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

	current_str = argv[arg_index];
	if (!ft_strlen(current_str))
		return (false);
	if (ft_isdigsig(*current_str))
		return (true);
	if (!arg_index)
		return (false);
	prev_str = argv[arg_index - 1];
	if (!ft_isdigit(prev_str[ft_strlen(prev_str) - 1]))
		return (false);
	return (true);
}

bool	is_valid_arg(int argc, const char **argv)
{
	int	arg_index;

	arg_index = 0;
	while (arg_index < argc)
	{
		if (!is_valid_arg_start(arg_index, argv))
			return (false);
		if (!is_valid_str(argv[arg_index]))
			return (false);
		//終端がスペースだった場合に、次の正しい引数がないときにfalseを返す
		if (argv[arg_index][0] != ' ' || !is_valid_arg_end(arg_index, argc,
				argv, argv[arg_index][1]))
			return (false);
		arg_index++;
	}
	return (true);
}
