/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_open_n_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:27:44 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/17 17:29:34 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				fdf_open(int argc, char **argv, int *fd)
{
	if (argc < 2)
	{
		ft_putendl("Usage: ./fdf source_file.fdf");
		return (0);
	}
	if ((*fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}

int				fdf_read(int *fd, int *num, t_field *field)
{
	char		*line;
	int 		height;
	int 		width;
	t_field		temp_field;

	height = 0;
	width = 0;
	while (get_next_line(*fd, &line) > 0)
	{
		if (height == 0)
			width = ft_count_words(line, ' ');
		printf("%s\n", line);
//		fdf_read_points(line, field);
		free(line);
		height++;
	}
	close(*fd);
	printf("\nWidth: %d\nHeight: %d", width, height);
	return (0);

}

int 			fdf_read_points(char *line, t_field *field)
{
	/* */
	return (0);
}

//int				fdf_read(int *fd, int *num, char **coordinates)
//{
//	int			number;
//	char		buff[545];
//
//	number = (int)read(*fd, buff, 545);
//	*coordinates = ft_strdup(buff);
//	*num = ((number + 2) / 21);
//	if (((number + 2) % 21) != 1)
//	{
//		ft_putendl("error");
//		return (0);
//	}
//	(*coordinates)[number] = '\0';
//	return (1);
//}