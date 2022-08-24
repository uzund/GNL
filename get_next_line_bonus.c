/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:37:44 by duzun             #+#    #+#             */
/*   Updated: 2022/08/19 21:37:44 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_satir_yap(char **str, int chars, char **buf)
{
	int		i;
	char	*line;
	char	*tmp;

	free(*buf);
	tmp = NULL;
	if (chars < 0 || *str == NULL)
		return (NULL);
	if (!chars && !ft_strchr(*str, '\n'))
	{
		line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (line);
	}
	i = 0;
	while ((*str)[i] != '\n')
		i++;
	line = ft_substr(*str, 0, i + 1);
	if ((int)ft_strlen(*str) - i - 1)
		tmp = ft_substr(*str, i + 1, ft_strlen(*str) - i - 1);
	free(*str);
	*str = tmp;
	return (line);
}

char	*get_next_line(const int fd)
{
	static char	*str[4096];
	char		*buf;
	char		*tmp;
	int			chrlen;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 4096)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	chrlen = read(fd, buf, BUFFER_SIZE);
	while (chrlen > 0)
	{
		buf[chrlen] = '\0';
		if (!str[fd])
			tmp = ft_strdup(buf);
		else
			tmp = ft_strjoin(str[fd], buf);
		str[fd] = tmp;
		if (ft_strchr(str[fd], '\n'))
			break ;
		chrlen = read(fd, buf, BUFFER_SIZE);
	}
	return (ft_satir_yap(&str[fd], chrlen, &buf));
}
