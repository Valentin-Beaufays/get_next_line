/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:42:30 by vbeaufay          #+#    #+#             */
/*   Updated: 2019/11/20 20:03:25 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

size_t	nlstrlen(char *str)
{
	size_t	i;

	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	return (i);
}

ssize_t	get_buf(int fd, char *buf)
{
	ssize_t len;
	if ((len = read(fd, buf, BUFFER_SIZE)) == -1)
		return (-1);
	buf[len] = '\0';
	return ((len > 0));
}

int		malloc_res(char **res, char *buf)
{
	char	*new;
	size_t	new_len;
	size_t	i;

	i = 0;
	new_len = nlstrlen(*res) + nlstrlen(buf) + 1;
	if (!(new = malloc(sizeof(char) * new_len)))
		return (0);
	while ((*res)[i])
	{
		new[i] = (*res)[i];
		i++;
	}
	while (*buf && *buf != '\n')
	{
		new[i] = *buf;
		i++;
		buf++;
	}
	new[i] = '\0';
	free(*res);
	*res = new;
	return (1);
}

int	init_res(char **res, char *buf)
{
	size_t	i;

	i = 0;
	if (!(*res = malloc(sizeof(char) * nlstrlen(buf))))
		return (0);
	while (buf[i] && buf[i] != '\n')
	{
		(*res)[i] = buf[i];
		i++;
	}
	(*res)[i] = '\0';
	return (1);
}

int	is_nl_in_buf(char *buf)
{
	while (*buf)
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

void	reset_buf(char *buf)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		i++;
		while (buf[i])
		{
			buf[j] = buf[i];
			i++;
			j++;
		}
	}
	buf[j] = '\0';
}

int		get_next_line(int fd, char **line)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE+1];
	char *res;
	int err;

	err = 1;
	if (!(init_res(&res, buf[fd])))
		err = -1;
	while (!(is_nl_in_buf(buf[fd])) && err > 0)
	{
		if ((err = get_buf(fd, buf[fd])) == -1)
			err = -1;
		if (!(malloc_res(&res, buf[fd])))
			err = -1;
	}
	if (err == -1)
		free(res);
	else
	{
		reset_buf(buf[fd]);
		if (*line)
			free(*line);
		*line = res;
	}
	return (err);
}
