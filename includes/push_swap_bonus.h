/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:57:45 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 08:04:34 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sysexits.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

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
char				*ft_calloc(size_t count, size_t size);
char				*ft_strchr(const char *s, int c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*get_next_line(int fd);

void				sa_bonus(t_stack *a);
void				sb_bonus(t_stack *b);
void				ss_bonus(t_stack *a, t_stack *b);
void				pa_bonus(t_stack *a, t_stack *b);
void				pb_bonus(t_stack *a, t_stack *b);
void				ra_bonus(t_stack *a);
void				rb_bonus(t_stack *b);
void				rr_bonus(t_stack *a, t_stack *b);
void				rra_bonus(t_stack *a);
void				rrb_bonus(t_stack *b);
void				rrr_bonus(t_stack *a, t_stack *b);

#endif
