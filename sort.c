/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 01:26:27 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/15 22:00:09 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack) {
  t_nord *guard_node;
  t_nord *node;

  guard_node = stack->guard_nord;
  node = guard_node->next;
  while (node != guard_node && node->next != guard_node) {
    if (node->value > node->next->value)
      return (false);
    node = node->next;
  }
  return (true);
}

void	sort(t_stack *a, t_stack *b) {
  t_nord *node;
  int size;

  node = a->guard_nord->next;
  size = a->size;
  if (is_sorted(a))
    return ;
  if (size == 1) {
    printf("sort_one_a\n");
    return ;
  } else if (size == 2) {
    printf("sort_two_a\n");
    if (node->value > node->next->value)
      sa(a);
  } else if (size == 3)
    sort_three_a(a);
  else if (size < 7)
    sort_six_or_less(a, b);
  else
    merge_sort(a, b);
}
