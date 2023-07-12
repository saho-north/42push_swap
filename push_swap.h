/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:07:15 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/12 18:23:37 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sysexits.h>
# include <unistd.h>

typedef struct s_nord
{
	struct s_nord	*next;
	struct s_nord	*prev;
	int				value;
	bool			is_guard_nord;
	bool			is_pivot;
}					t_nord;

typedef struct s_stack
{
	t_nord			*guard_nord;
	int				size;
}					t_stack;
void				print_stack(t_nord *guard_nord);
t_stack				*parse_input(int argc, const char **argv);

void				exit_with_print_error(void);
void				free_stack(t_stack *stack);
void				free_stack_with_error(t_stack *stack);
void				free_stacks_with_error(t_stack *stack_a, t_stack *stack_b);

int					ft_isdigit(int c);
void				ft_putendl_fd(char *s, int fd);
size_t				ft_strlen(const char *str);
long				ft_strtol(const char *str, const char **endpos);
bool				is_valid_arg(int argc, const char **argv);
#endif
