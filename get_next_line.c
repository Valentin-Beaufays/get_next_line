/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:42:30 by vbeaufay          #+#    #+#             */
/*   Updated: 2019/11/05 20:55:20 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	static int	lnumber;
	char		*buffer;

	if(!(buffer = malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	
	return (0);
}

int main(void)
{
	get_next_line(0, 0);
	get_next_line(0, 0);
}
