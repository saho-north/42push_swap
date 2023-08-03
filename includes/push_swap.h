/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:07:15 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/03 23:54:21 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap_common.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <sysexits.h>
# include <unistd.h>

# define STACK_A 1
# define STACK_B 0

void	compaction(t_stack *stack);
t_stack	*create_empty_stack(void);
void	exit_with_print_error(void);
void	free_stack(t_stack *stack);
void	free_stack_with_print_error(t_stack *stack);
void	free_stacks_with_print_error(t_stack *a, t_stack *b);
int		ft_isdigit(int c);
int		ft_isdigsig(int c);
int		ft_issign(int c);
void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
long	ft_strtol(const char *str, const char **endpos);
bool	is_reverse_sorted(t_stack *stack, size_t size);
bool	is_sorted(t_stack *stack, size_t size);
bool	is_valid_arg(int argc, const char **argv);
void	multi_rrr(t_stack *a, t_stack *b, size_t count);
t_stack	*parse_input(int argc, const char **argv);
void	partition_a(t_stack *a, t_stack *b, size_t size, size_t max_id);
void	partition_b(t_stack *a, t_stack *b, size_t size, size_t min_id);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b, size_t size, bool type);
void	sort(t_stack *a, t_stack *b);

#endif
