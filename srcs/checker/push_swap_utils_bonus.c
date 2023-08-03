/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 01:06:41 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 08:05:58 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

size_t	ft_strlen(const char *str) {
  size_t i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	ft_issign(int c) { return (c == '+' || c == '-'); }

int	ft_isdigit(int c) { return ('0' <= c && c <= '9'); }

int	ft_isdigsig(int c) { return (ft_isdigit(c) || ft_issign(c)); }

void	ft_putendl_fd(char *s, int fd) {
  if (!s)
    return ;
  write(fd, s, ft_strlen(s));
  write(fd, "\n", 1);
}
