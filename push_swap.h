/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:07:15 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/10 15:32:50 by sakitaha         ###   ########.fr       */
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

typedef struct s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
	bool			is_sentinel;
	bool			is_pivot;
}					t_list;

bool				is_valid_arg(int argc, const char **argv);
int					ft_isdigit(int c);
void				exit_with_error(void);
t_list				*build_stack(int argc, const char **argv);
long long			ft_strtoll(const char *str);
void				lst_clear(t_list **lst);
t_list				*create_node(int value, t_list **head);
void				exit_with_error_and_free(t_list *ptr);
size_t				ft_strlen(const char *str);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
#endif
