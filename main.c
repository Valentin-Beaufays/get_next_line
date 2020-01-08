/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:47:12 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/01/07 20:41:55 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>

/*int main(void)
{
	char	*res;
	char	*buf;

	res = malloc(sizeof(char) * 10);
	buf = malloc(sizeof(char) * 10);

	memset(res, 'a', 10);
	memset(buf, 'b', 10);

	res[9] = 0;
	buf[9] = 0;

	malloc_res(&res, buf);
	printf("%s", res);
	free(res);
	free(buf);
	return (0);
}*/

void	test_malloc_res();

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
	for(int i = 0; i < 50; i++)
	{
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
	close(fd);
	//close(fd2);
	return (0);
}

void	test_malloc_res(void)
{
	char *str;
	char *buf;

	str = malloc(sizeof(*str) * 4);
	str[0] = 'c';
	str[1] = 'o';
	str[2] = 'm';
	str[3] = 0;
	buf = "ment va t";
	printf("%s\n", str);
	malloc_res(&str, buf);
	printf("%s\n", str);
}
