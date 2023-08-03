/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:00:57 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 04:30:09 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

char	*ft_calloc(size_t count, size_t size)
{
	char	*buffer;
	size_t	buf_size;
	size_t	i;

	buf_size = count * size;
	if (count > 0 && size > 0 && buf_size / count < size)
		return (NULL);
	buffer = (void *)malloc(buf_size);
	if (buffer)
	{
		i = 0;
		while (i < buf_size)
			buffer[i++] = '\0';
	}
	return (buffer);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	to_find;

	str = (char *)s;
	to_find = (char)c;
	while (str && *str)
	{
		if (*str == to_find)
			return (str);
		str++;
	}
	if (str && *str == to_find)
		return (str);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptrdest;
	char	*ptrsrc;

	ptrdest = (char *)dst;
	ptrsrc = (char *)src;
	if (!ptrdest && !ptrsrc)
		return (NULL);
	while (n--)
		*(ptrdest++) = *(ptrsrc++);
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	srclen;

	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if ((size_t)start >= srclen)
		len = 0;
	else if (len > srclen - (size_t)start)
		len = srclen - (size_t)start;
	substr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	substr = ft_memcpy(substr, s + start, len);
	return (substr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
