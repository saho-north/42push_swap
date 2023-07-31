/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compaction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:14:52 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/01 04:52:51 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// static void	ft_sort_int_tab(int *tab, size_t size)
// {
// 	size_t	i;
// 	size_t	j;
// 	bool	sorted;

// 	i = 0;
// 	while (i + 1 < size)
// 	{
// 		j = 0;
// 		sorted = true;
// 		while (i + j + 1 < size)
// 		{
// 			if (tab[j] > tab[j + 1])
// 			{
// 				ft_swap(&tab[j], &tab[j + 1]);
// 				sorted = false;
// 			}
// 			j++;
// 		}
// 		if (sorted)
// 			break ;
// 		i++;
// 	}
// }

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

static int	*create_tmp_array(t_stack *stack, size_t size)
{
	t_node	*node;
	int		*array;
	size_t	i;

	node = stack->guard->next;
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
	return (array);
}

void	compaction(t_stack *stack)
{
	t_node	*node;
	int		*array;
	size_t	size;
	size_t	i;
	size_t	j;

	node = stack->guard->next;
	size = stack->size;
	array = create_tmp_array(stack, size);
	ft_sort_int_tab(array, size);
	i = 0;
	while (i < size && node != stack->guard)
	{
		j = 0;
		while (j < size)
		{
			if (node->value == array[j])
			{
				node->index = j;
				break ;
			}
			j++;
		}
		node = node->next;
		i++;
	}
	free(array);
}
