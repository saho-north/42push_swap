/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:07:15 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/13 18:14:35 by sakitaha         ###   ########.fr       */
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
	int				min;
	int				max;
	int				median;
	bool			is_sorted;
	bool			is_reverse_sorted;
	bool			is_sorted_except_top;
	bool			is_sorted_except_bottom;
	bool			is_sorted_except_top_and_bottom;
}					t_stack;

void				print_stack(t_stack *stack);

t_stack				*create_empty_stack(void);

void				exit_with_print_error(void);
void				free_stack(t_stack *stack);
void				free_stack_with_error(t_stack *stack);
void				free_stacks_with_error(t_stack *stack_a, t_stack *stack_b);

int					ft_isdigit(int c);
int					ft_isdigsig(int c);
int					ft_issign(int c);
void				ft_putendl_fd(char *s, int fd);
size_t				ft_strlen(const char *str);
long				ft_strtol(const char *str, const char **endpos);
bool				is_valid_arg(int argc, const char **argv);

t_stack				*parse_input(int argc, const char **argv);

void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);

#endif
