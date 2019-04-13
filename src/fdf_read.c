/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:46:58 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/13 15:47:29 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				fdf_help(int *fd, t_field *field, t_list_p *list_p)
{
	char		*line;
	int			rd;
	int			check;

	rd = 0;
	check = 0;
	while ((rd = get_next_line(*fd, &line)) > 0)
	{
		if (field->height == 0)
			field->width = ft_count_words(line, ' ');
		else if (ft_count_words(line, ' ') != field->width
		|| !ft_strcmp(line, ""))
			return (0);
		list_p->points = (t_point*)malloc(sizeof(t_point) * (field->width + 1));
		if (!fdf_read_points(line, list_p, field))
			return (0);
		field->height++;
		list_p->next_p = (t_list_p*)malloc(sizeof(t_list_p));
		list_p = list_p->next_p;
		free(line);
		check++;
	}
	if (rd == 0 && check == 0)
		return (0);
	return (1);
}

int				fdf_read(int *fd, t_field *field, char *map_name)
{
	t_list_p	*list_p;
	t_list_p	*head;

	if (!(list_p = (t_list_p*)malloc(sizeof(t_list_p))))
		return (0);
	fdf_field_init(field);
	field->color_height = FALSE;
	field->color_shift = 0;
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
		if (field->points_mem[i].z > field->max_z)
			field->max_z = field->points_mem[i].z;
		if (field->points_mem[i].z < field->max_z)
			field->min_z = field->points_mem[i].z;
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

int				fdf_read_points(char *line, t_list_p *list, t_field *field)
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
		if (!(list->points[i].color = fdf_find_color(array[i - 1])))
			return (0);
		list->points[i].z = ft_atoi(array[i - 1]);
		i++;
	}
	return (1);
}
