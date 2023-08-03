/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:57:45 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 03:55:59 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap_common.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*get_next_line(int fd);

void	sa_bonus(t_stack *a);
void	sb_bonus(t_stack *b);
void	ss_bonus(t_stack *a, t_stack *b);
void	pa_bonus(t_stack *a, t_stack *b);
void	pb_bonus(t_stack *a, t_stack *b);
void	ra_bonus(t_stack *a);
void	rb_bonus(t_stack *b);
void	rr_bonus(t_stack *a, t_stack *b);
void	rra_bonus(t_stack *a);
void	rrb_bonus(t_stack *b);
void	rrr_bonus(t_stack *a, t_stack *b);

#endif
