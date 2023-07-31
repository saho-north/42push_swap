/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:07:15 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/01 00:59:17 by sakitaha         ###   ########.fr       */
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

# define STACK_A true
# define STACK_B false

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
	int				size;
}					t_stack;

void				partition(t_stack *a, t_stack *b, size_t size_a,
						size_t size_b);
void				partition_for_stack_a(t_stack *a, t_stack *b, size_t size);
void				partition_for_stack_b(t_stack *a, t_stack *b, size_t size);

void				compaction(t_stack *stack);

void				print_stack(t_stack *stack);
void				print_stacks(t_stack *a, t_stack *b);

t_stack				*create_empty_stack(void);

void				exit_with_print_error(void);
void				free_stack(t_stack *stack);
void				free_stack_with_print_error(t_stack *stack);
void				free_stacks_with_print_error(t_stack *a, t_stack *b);

int					ft_isdigit(int c);
int					ft_isdigsig(int c);
int					ft_issign(int c);
void				ft_putendl_fd(char *s, int fd);
size_t				ft_strlen(const char *str);
long				ft_strtol(const char *str, const char **endpos);
int					get_pivot(t_stack *stack, size_t size);
bool				is_reverse_sorted(t_stack *stack, size_t size);
bool				is_sorted(t_stack *stack, size_t size);
bool				is_valid_arg(int argc, const char **argv);

t_stack				*parse_input(int argc, const char **argv);

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

void				sort(t_stack *a, t_stack *b);
void				sort_small(t_stack *a, t_stack *b, size_t size, bool type);

// to be deleted later on
void				print_stack(t_stack *stack);
void				print_stacks_final(t_stack *a, t_stack *b);

#endif
