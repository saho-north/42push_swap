/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:32:34 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 04:44:39 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

static void	execute_command(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 4))
		sa_bonus(a);
	else if (!ft_strncmp(line, "sb\n", 4))
		sb_bonus(b);
	else if (!ft_strncmp(line, "ss\n", 4))
		ss_bonus(a, b);
	else if (!ft_strncmp(line, "pa\n", 4))
		pa_bonus(a, b);
	else if (!ft_strncmp(line, "pb\n", 4))
		pb_bonus(a, b);
	else if (!ft_strncmp(line, "ra\n", 4))
		ra_bonus(a);
	else if (!ft_strncmp(line, "rb\n", 4))
		rb_bonus(b);
	else if (!ft_strncmp(line, "rr\n", 4))
		rr_bonus(a, b);
	else if (!ft_strncmp(line, "rra\n", 5))
		rra_bonus(a);
	else if (!ft_strncmp(line, "rrb\n", 5))
		rrb_bonus(b);
	else if (!ft_strncmp(line, "rrr\n", 5))
		rrr_bonus(a, b);
}

static bool	is_valid_command(char *line)
{
	if (!ft_strncmp(line, "sa\n", 4) || !ft_strncmp(line, "sb\n", 4))
		return (true);
	else if (!ft_strncmp(line, "ss\n", 4))
		return (true);
	else if (!ft_strncmp(line, "pa\n", 4) || !ft_strncmp(line, "pb\n", 4))
		return (true);
	else if (!ft_strncmp(line, "ra\n", 4) || !ft_strncmp(line, "rb\n", 4))
		return (true);
	else if (!ft_strncmp(line, "rr\n", 4))
		return (true);
	else if (!ft_strncmp(line, "rra\n", 5) || !ft_strncmp(line, "rrb\n", 5))
		return (true);
	else if (!ft_strncmp(line, "rrr\n", 5))
		return (true);
	else
		return (false);
}

static void	read_command_and_execute(t_stack *a, t_stack *b)
{
	char	*line;

	while (true)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!is_valid_command(line))
		{
			free(line);
			free_stacks_with_print_error(a, b);
		}
		execute_command(a, b, line);
		free(line);
		line = NULL;
	}
}

int	main(int argc, const char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	if (!is_valid_arg(--argc, ++argv))
		exit_with_print_error();
	a = parse_input(argc, argv);
	if (!a)
		exit_with_print_error();
	b = create_empty_stack();
	if (!b)
		free_stack_with_print_error(a);
	read_command_and_execute(a, b);
	if (is_sorted(a, a->size) && b->guard->next == b->guard->prev)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stack(a);
	free_stack(b);
	return (0);
}
