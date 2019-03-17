/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_open_n_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:27:44 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/17 19:56:41 by fsmith           ###   ########.fr       */
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
	t_field		temp_field;

	field_init(&temp_field);
	temp_field.height = 0;
	while (get_next_line(*fd, &line) > 0)
	{
		if (temp_field.height == 0)
			temp_field.width = ft_count_words(line, ' ');
		temp_field.height++;
		printf("%s\n", line);
		fdf_read_points(line, &temp_field);
		free(line);
	}
	close(*fd);
	printf("\nWidth: %d\nHeight: %d", temp_field.width, temp_field.height);
	*field = temp_field;
	return (1);
}

int 			fdf_read_points(char *line, t_field *field)
{
	/* */
	int			i;
	t_point		*p;
	char		**array;

	array = ft_strsplit(line, ' ');
	p = (t_point *)malloc(sizeof(t_point) * (field->width + 1));
	i = 1;
	while (i <= field->width)
	{
		p[i].n = i * field->height;
		p[i].x = i;
		p[i].y = field->height;
		p[i].z = ft_atoi(array[i - 1]);
		if (field->max_depth < p[i].z)
			field->max_depth = p[i].z;
//		p[i].color = find_color();
		i++;
	}
	field->points = p;
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