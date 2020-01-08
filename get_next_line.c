/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:22:34 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/01/08 16:46:55 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_buffer(int fd, char *buf, size_t size)
{
	ssize_t	len;

	if ((len = read(fd, buf, size)) == -1)
		return (-1);
	buf[len] = 0;
	return ((len != 0));
}

size_t	ft_strnllen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int		malloc_res(char **res, char *buf)
{
	char	*new;
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	if (!(new = malloc(sizeof(**res)
					* (ft_strnllen(*res) + ft_strnllen(buf) + 1))))
		return (0);
	while (*res && (*res)[i])
	{
		new[i] = (*res)[i];
		i++;
	}
	while (buf[j] && buf[j] != '\n')
	{
		new[i] = buf[j];
		j++;
		i++;
	}
	new[i] = 0;
	if (*res)
		free(*res);
	*res = new;
	return (1);
}

int		is_nl_into(char *str)
{
	while (str && *str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int		reset_buffer(char *buf)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		buf[0] = 0;
		return (0);
	}
	while (buf[j + i])
	{
		buf[j] = buf[j + i + 1];
		j++;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static	char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char			*res;
	int				eof;

	res = 0;
	eof = 1;
	if (fd < 0 || !line || !(malloc_res(&res, buf[fd])))
		return (-1);
	while (eof > 0 && !is_nl_into(buf[fd]))
	{
		if ((eof = get_buffer(fd, buf[fd], BUFFER_SIZE)) == -1)
		{
			free(res);
			return (-1);
		}
		if (!(malloc_res(&res, buf[fd])))
		{
			free(res);
			return (-1);
		}
	}
	*line = res;
	if (!reset_buffer(buf[fd]) && !eof && !*res)
		return (0);
	return (1);
}
