/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:42:30 by vbeaufay          #+#    #+#             */
/*   Updated: 2019/11/18 23:30:09 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	get_buffer(int fd, char *buffer)
{
	ssize_t len;
	if ((len = read(fd, buffer, BUFFER_SIZE)) == -1)
		return (-1);
	buffer[len] = '\0';
	return (len);
}

int		malloc_res(char *res, char *buffer)
{
	
}

int		get_next_line(int fd, char **line)
{
	static char	buffers[OPEN_MAX][BUFFER_SIZE+1];
	ssize_t		size;
	char		*res;

	if ((malloc_res(res, buffers[fd])))
		return (-1);
	if ((size = get_buffer(fd, buffers[fd])) == -1)
		return (-1);

	return (0);
}
