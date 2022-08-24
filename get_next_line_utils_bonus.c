/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:39:04 by duzun             #+#    #+#             */
/*   Updated: 2022/08/19 21:39:04 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (*str == '\0')
	{
		if ((char)c == '\0')
			return (str);
		return (NULL);
	}
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == (char)c)
		return (str);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_strlen(s);
	if (start >= count)
		return (ft_strdup(""));
	if (count < len)
		len = count;
	dst = (char *)malloc(sizeof(*s) * (len + 1));
	if (!dst)
		return (NULL);
	i = start;
	j = 0;
	while (i < count && j < len)
		dst[j++] = s[i++];
	dst[j] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(dst + i) = *(s1 + i);
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	dst = (char *)malloc(sizeof(*s1) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s1 + i))
	{
		dst[j++] = s1[i++];
	}
	i = 0;
	while (*(s2 + i))
		dst[j++] = s2[i++];
	dst[j] = '\0';
	free(s1);
	return (dst);
}
