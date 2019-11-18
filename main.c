/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:47:12 by vbeaufay          #+#    #+#             */
/*   Updated: 2019/11/18 23:30:12 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	/*get_next_line(0,0);
	while(1)
	{
	}*/
	char hread[11];
	int fd;
	fd = open("test.txt", O_RDONLY);
	read(fd, hread, 1);
	hread[1] = '\0';
	printf("1: %s\n", hread);
	read(fd, hread, -1);
	printf("2: %s\n", hread);
	return (0);
}
