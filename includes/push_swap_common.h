/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_common.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:52:13 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 03:54:34 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_COMMON_H
# define PUSH_SWAP_COMMON_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sysexits.h>
# include <unistd.h>

# define STACK_A 1
# define STACK_B 0

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				value;
	size_t			index;
}					t_node;

typedef struct s_stack
{
	t_node			*guard;
	size_t			size;
}					t_stack;

bool				is_valid_arg(int argc, const char **argv);
t_stack				*parse_input(int argc, const char **argv);
t_stack				*create_empty_stack(void);
bool				is_sorted(t_stack *stack, size_t size);
bool				is_reverse_sorted(t_stack *stack, size_t size);

size_t				ft_strlen(const char *str);
int					ft_issign(int c);
int					ft_isdigit(int c);
int					ft_isdigsig(int c);
void				ft_putendl_fd(char *s, int fd);
long				ft_strtol(const char *str, const char **endpos);

//exit_with_error.c
void				exit_with_print_error(void);
void				free_stack(t_stack *stack);
void				free_stack_with_print_error(t_stack *stack);
void				free_stacks_with_print_error(t_stack *a, t_stack *b);

//do_commanc.c
void				swap(t_stack *stack);
void				push(t_stack *stack_from, t_stack *stack_to);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);

#endif
