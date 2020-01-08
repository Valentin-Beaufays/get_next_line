/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:47:12 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/01/08 18:14:04 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	//test_malloc_res();
	int	fd;
	//int	fd2;
	char *line;
	int ret;

	line = 0;
	fd = open("test.txt", O_RDONLY);
	//printf("\nfd: %d\n", fd);
	for (int i = 0; i < 25; i++)
	{
		if (line)
			free(line);
		ret = get_next_line(fd, &line);
		printf("result = %s\n", line);
		printf(" return: %d\n", ret);
	}
	/*fd2 = open("test2.txt", O_RDONLY);
	printf("\nfd: %d\n", fd2);
	for(int i = 0; i < 5; i++)
	{
		get_next_line(fd2, &line);
		printf("%s\n", line);
	}
	printf("\nfd: %d\n", fd);
	for(int i = 0; i < 5; i++)
	{
		get_next_line(fd, &line);
		printf("%s\n", line);
	}*/
	if (line)
		free(line);
	close(fd);
	//close(fd2);
	return (0);
}
