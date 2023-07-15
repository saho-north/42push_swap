/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 01:26:27 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/15 22:00:09 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_value(t_stack *stack) {
  t_nord *node;
  int min;

  node = stack->guard_nord->next;
  min = node->value;
  while (node != stack->guard_nord) {
    if (min > node->value)
      min = node->value;
    node = node->next;
  }
  return (min);
}

// b側のソートは後で逆順に改善する必要がある

void	sort_three_b(t_stack *b) {
  t_nord *guard_node;
  int first;
  int second;
  int last;

  printf("sort_three_b\n");
  guard_node = b->guard_nord;
  first = guard_node->next->value;
  second = guard_node->next->next->value;
  last = guard_node->prev->value;
  while (first < second || second < last) {
    if (first < second && second > last && first < last)
      rb(b);
    else if (first > second && second < last && first < last)
      rrb(b);
    else
      sb(b);
    first = guard_node->next->value;
    second = guard_node->next->next->value;
    last = guard_node->prev->value;
  }
}

void	sort_small_b(t_stack *b) {
  t_nord *node;
  int size;

  printf("sort_small_b\n");
  size = b->size;
  node = b->guard_nord->next;
  if (size == 1)
    return ;
  else if (size == 2) {
    if (node->value > node->next->value)
      sb(b);
  } else if (size == 3)
    sort_three_b(b);
}

void	sort_three_a(t_stack *a) {
  t_nord *guard_node;
  int first;
  int second;
  int last;

  printf("sort_three_a\n");
  guard_node = a->guard_nord;
  first = guard_node->next->value;
  second = guard_node->next->next->value;
  last = guard_node->prev->value;
  while (first > second || second > last) {
    if (first > second && second < last && first > last)
      ra(a);
    else if (first < second && second > last && first > last)
      rra(a);
    else
      sa(a);
    first = guard_node->next->value;
    second = guard_node->next->next->value;
    last = guard_node->prev->value;
  }
}

void	sort_six_or_less(t_stack *a, t_stack *b) {
  t_nord *guard_a;
  int min;

  printf("sort_six_or_less\n");
  guard_a = a->guard_nord;
  while (a->size != 3) {
    min = get_min_value(a);
    if (guard_a->next->value == min)
      pb(a, b);
    else if (guard_a->prev->value == min)
      rra(a);
    else if (guard_a->prev->prev->value == min)
      rra(a);
    else
      ra(a);
  }
  sort_three_a(a);
  while (b->size > 0)
    pa(a, b);
}
