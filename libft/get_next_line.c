/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:30:39 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/02 15:26:56 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			gnl_extend_line(int fd, char **line1)
{
	char			*line2;
	char			*temp;
	ssize_t			read_len;

	line2 = ft_strnew(BUFF_SIZE);
	read_len = read(fd, line2, BUFF_SIZE);
	if (read_len == 0)
	{
		free(line2);
		return (0);
	}
	line2[read_len] = '\0';
	temp = ft_strdup(*line1);
	free(*line1);
	*line1 = ft_strjoin(temp, line2);
	free(temp);
	free(line2);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*line1[MAX_FD];

	if (fd < 0 || line == NULL || read(fd, NULL, 0) < 0 || fd > MAX_FD)
		return (-1);
	if (!line1[fd])
	{
		line1[fd] = ft_strnew(BUFF_SIZE);
		line1[fd][read(fd, line1[fd], BUFF_SIZE)] = '\0';
	}
	while (!ft_strchr(line1[fd], '\n'))
	{
		if (gnl_extend_line(fd, &line1[fd]) == 0)
		{
			if (*line == line1[fd])
				return (0);
			*line = line1[fd];
			if (ft_strcmp(*line, "") == 0)
				return (0);
			return (1);
		}
	}
	*line = ft_strcut(&line1[fd], '\n');
	return (1);
}
