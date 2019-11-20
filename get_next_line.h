/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:42:32 by vbeaufay          #+#    #+#             */
/*   Updated: 2019/11/20 17:19:18 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
int		malloc_res(char **res, char *buf);
size_t	nlstrlen(char *str);
ssize_t	get_buf(int fd, char *buf);
int		init_res(char **res, char *buf);
int		is_nl_in_buf(char *buf);
void	reset_buf(char *buf);

#endif
