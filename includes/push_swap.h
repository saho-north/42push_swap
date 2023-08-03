/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:07:15 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 08:03:54 by sakitaha         ###   ########.fr       */
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

void				exit_with_print_error(void);
void				free_stack(t_stack *stack);
void				free_stack_with_print_error(t_stack *stack);
void				free_stacks_with_print_error(t_stack *a, t_stack *b);

void				swap(t_stack *stack);
void				push(t_stack *stack_from, t_stack *stack_to);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);
void				compaction(t_stack *stack);

bool				is_reverse_sorted(t_stack *stack, size_t size);
void				partition_a(t_stack *a, t_stack *b, size_t size,
						size_t max_id);
void				partition_b(t_stack *a, t_stack *b, size_t size,
						size_t min_id);

void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				multi_rrr(t_stack *a, t_stack *b, size_t count);
void				sort_small(t_stack *a, t_stack *b, size_t size, bool type);
void				sort(t_stack *a, t_stack *b);

#endif
