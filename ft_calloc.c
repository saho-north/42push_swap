/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:44:24 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/07 08:39:41 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buf;
	size_t	buf_size;

	buf_size = count * size;
	if (count != 0 && buf_size / count != size)
		return (NULL);
	buf = (void *)malloc(buf_size);
	if (buf)
		ft_bzero(buf, buf_size);
	return (buf);
}
