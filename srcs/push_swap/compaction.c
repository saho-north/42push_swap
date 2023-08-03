/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compaction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:14:52 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 04:30:09 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_sort_int_tab(int *tab, size_t size)
{
	size_t	i;
	bool	sorted;

	sorted = false;
	while (!sorted)
	{
		sorted = true;
		i = 0;
		while (i + 1 < size)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				sorted = false;
			}
			i++;
		}
	}
}

static int	*create_sorted_array(t_stack *stack)
{
	t_node	*node;
	int		*array;
	size_t	i;
	size_t	size;

	node = stack->guard->next;
	size = stack->size;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		free_stack_with_print_error(stack);
	i = 0;
	while (i < size && node != stack->guard)
	{
		array[i] = node->value;
		node = node->next;
		i++;
	}
	ft_sort_int_tab(array, size);
	return (array);
}

void	compaction(t_stack *stack)
{
	t_node	*node;
	int		*array;
	size_t	array_index;

	node = stack->guard->next;
	array = create_sorted_array(stack);
	while (node != stack->guard)
	{
		array_index = 0;
		while (array_index < stack->size)
		{
			if (node->value == array[array_index])
			{
				node->index = array_index;
				break ;
			}
			array_index++;
		}
		node = node->next;
	}
	free(array);
}
