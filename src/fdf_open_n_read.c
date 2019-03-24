/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_open_n_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:27:44 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/24 18:51:59 by fsmith           ###   ########.fr       */
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

int				fdf_read(int *fd, int *num, t_field *field, char *map_name)
{
	char		*line;
	t_list_p	*list_p;
	t_list_p	*head;
	t_point		*point;

	if (!(list_p = (t_list_p*)malloc(sizeof(t_list_p))))
		return (0);
	fdf_field_init(field);
	field->height = 0;
	field->map_name = map_name;
	head = list_p;
	while (get_next_line(*fd, &line) > 0)
	{
		if (field->height == 0)
			field->width = ft_count_words(line, ' ');
		else if (ft_count_words(line, ' ') != field->width)
		{
			ft_putstr("Invalid map");
			return (0);
		}
		list_p->points = (t_point*)malloc(sizeof(t_point) * (field->width + 1)); // выделение памяти для массива поинтов листе
		fdf_read_points(line, list_p, field);
		field->height++;
		list_p->next_p = (t_list_p*)malloc(sizeof(t_list_p)); // выделение памяти для следующего листа
		list_p = list_p->next_p; // переход к следующему листу
		free(line);
	}
	field->points = (t_point*)malloc(sizeof(*point) * ((field->width + 1) * (field->height + 1)));
	field->points = ft_peresapis(field, head);
	close(*fd);
	return (1);
}

void		ft_place(t_field *field)
{
	double x0 = field->points[1].x;
	double y0 = field->points[1].y;
	fdf_isometry(&x0, &y0, field->points[1].z, field->angle_x);
	field->x0 = x0;
	field->y0 = y0;
}

t_point		*ft_peresapis(t_field *field, t_list_p *list_p)
{
	double *step;
	int h;
	int w;
	int w1;
	int i;

	w = field->width;
	h = field->height;
	step = (double*)malloc(sizeof(double) * 4);
	fdf_start_values(step, field);
	i = 1;
	double x = step[1];
	w1 = 1;
	while (h > 0)
	{
		while (w > 0)
		{
			field->points[i].n = i;
			field->points[i].x = x;
			field->points[i].y = step[2];
			field->points[i].z = (list_p->points)[w1].z * Z_COEFF;
			field->points[i].color = (list_p->points)[w1].color;
			w--;
			w1++;
			x += step[0];
//			printf("%f\n", step[1]);
			i++;
		}
		w1 = 1;
		list_p = list_p->next_p;
		w = field->width;
		step[2] += step[0];
		x = step[1];
		h--;
	}
	return (field->points);
}

void		fdf_read_points(char *line, t_list_p *list, t_field *field)
{
	int			i;
	char		**array;

	/* Need to add some checks to colors and extra symbols */
	array = ft_strsplit(line, ' ');
	i = 1;
	while (i <= field->width)
	{
		(list->points)[i].n = i + (field->height * field->width);
		list->points[i].x = i;
		list->points[i].y = field->height;
		list->points[i].z = ft_atoi(array[i - 1]);
		if (field->max_depth < list->points[i].z)
			field->max_depth = list->points[i].z;
		list->points[i].color = fdf_find_color(array[i - 1]);
//		printf("%d\n", list->points[i].color);
		i++;
	}
}

int			fdf_find_color(char *str)
{
	char	*color_string;
	int		color;

	color_string = strchr(str, ',');
	if (!color_string)
	{
		return (DEFAULT_COLOR);
	}
	color = ft_atoi_hex(color_string + 1);
	if (color >= 0)
	{
		return (color);
	}
	return (DEFAULT_COLOR);
}
