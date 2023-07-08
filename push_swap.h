/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:07:15 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/09 01:21:32 by sakitaha         ###   ########.fr       */
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

bool				is_valid_arg(int argc, const char **argv);
int					ft_isdigit(int c);
void				print_error(void);
t_list				*stack_init(int argc, char **argv);
int					str_to_int(const char *str, t_list **head);
void				print_error_free(t_list *ptr);
t_list				*lst_new(int value, t_list **head);
#endif
