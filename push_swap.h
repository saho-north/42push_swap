/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:07:15 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/07 17:16:56 by sakitaha         ###   ########.fr       */
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

void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
int					ft_isdigit(int c);
void				error(void);
void				stack_init(int argc, char **argv);
t_list				*lst_new(int value, t_list *prev, t_list *next);
int					ft_atol(const char *str);
void				lst_clear(t_list **lst);
void				lst_add_back(t_list **lst, t_list *new);
t_list				*lst_last(t_list *lst);

typedef struct s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
	// bool			is_sorted;
	// bool			is_pivot;
}					t_list;

#endif
