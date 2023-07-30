/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compaction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:14:52 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/29 13:25:22 by sakitaha         ###   ########.fr       */
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

static void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	swap_count;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		swap_count = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(&tab[j], &tab[j + 1]);
				swap_count++;
			}
			j++;
		}
		if (swap_count == 0)
			break ;
		i++;
	}
}

static int	*create_array(t_stack *stack, int size)
{
	t_node	*node;
	int		*array;
	int		i;

	if (size < 2)
		return (NULL);
	node = stack->guard->next;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		exit_with_print_error();
	i = 0;
	while (i < size)
	{
		array[i] = node->value;
		node = node->next;
		i++;
	}
	return (array);
}

void	compaction(t_stack *stack, int size)
{
	t_node	*node;
	int		*array;
	int		i;
	int		j;

	node = stack->guard->next;
	array = create_array(stack, size);
	ft_sort_int_tab(array, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (node->value == array[j])
			{
				node->compressedValue = j;
				break ;
			}
			j++;
		}
		node = node->next;
		i++;
	}
	free(array);
}
