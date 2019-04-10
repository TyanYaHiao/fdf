/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:46:58 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/10 19:14:43 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				fdf_help(int *fd, t_field *field, t_list_p *list_p)
{
	char		*line;

	while (get_next_line(*fd, &line) > 0)
	{
		if (field->height == 0)
			field->width = ft_count_words(line, ' ');
		else if (ft_count_words(line, ' ') != field->width)
			return (0);
		list_p->points = (t_point*)malloc(sizeof(t_point) * (field->width + 1));
		fdf_read_points(line, list_p, field);
		field->height++;
		list_p->next_p = (t_list_p*)malloc(sizeof(t_list_p));
		list_p = list_p->next_p;
		free(line);
	}
	return (1);
}

int				fdf_read(int *fd, int *num, t_field *field, char *map_name)
{
	t_list_p	*list_p;
	t_list_p	*head;

	if (!(list_p = (t_list_p*)malloc(sizeof(t_list_p))))
		return (0);
	fdf_field_init(field);
	field->map_name = map_name;
	head = list_p;
	if (!fdf_help(fd, field, head))
	{
		ft_putstr("Invalid map");
		return (0);
	}
	field->points_mem = (t_point*)malloc(sizeof(t_point) * ((field->width + 1)
			* (field->height + 1)));
	field->points_out = (t_point*)malloc(sizeof(t_point) * ((field->width + 1)
			* (field->height + 1)));
	field->current = (t_curr*)malloc(sizeof(*(field->current)));
	field->points_mem = fdf_write_in_points(field, head);
	fdf_points_copy(field);
	close(*fd);
	return (1);
}

void			fdf_cycle(t_field *field, t_list_p *list_p, double *step, int i)
{
	int			w1;
	double		x;
	int			w;

	x = step[1];
	w1 = 1;
	w = field->width;
	while (w > 0)
	{
		field->points_mem[i].n = i;
		field->points_mem[i].x = x;
		field->points_mem[i].y = step[2];
		field->points_mem[i].z = (list_p->points)[w1].z;
		field->points_mem[i].color = (list_p->points)[w1].color;
		w--;
		w1++;
		x += step[0];
		i++;
	}
}

t_point			*fdf_write_in_points(t_field *field, t_list_p *list_p)
{
	double		*step;
	int			h;
	double		x;
	int			i;

	i = 1;
	h = field->height;
	step = (double*)malloc(sizeof(double) * 4);
	fdf_start_values(step, field);
	while (h > 0)
	{
		fdf_cycle(field, list_p, step, i);
		i += field->width;
		list_p = list_p->next_p;
		step[2] += step[0];
		h--;
	}
	return (field->points_mem);
}

void			fdf_read_points(char *line, t_list_p *list, t_field *field)
{
	int			i;
	char		**array;

	array = ft_strsplit(line, ' ');
	i = 1;
	while (i <= field->width)
	{
		(list->points)[i].n = i + (field->height * field->width);
		list->points[i].x = i;
		list->points[i].y = field->height;
		list->points[i].z = ft_atoi(array[i - 1]);
		list->points[i].color = fdf_find_color(array[i - 1]);
		i++;
	}
}

int				fdf_find_color(char *str)
{
	char		*color_string;
	int			color;

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
