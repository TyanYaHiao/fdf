/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:46:58 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/02 15:26:56 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				fdf_read(int *fd, int *num, t_field *field, char *map_name)
{
	char		*line;
	t_list_p	*list_p;
	t_list_p	*head;
	t_point		*point;
	int 		i;

	if (!(list_p = (t_list_p*)malloc(sizeof(t_list_p))))
		return (0);
	fdf_field_init(field);
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
	field->points_mem = (t_point*)malloc(sizeof(t_point) * ((field->width + 1) * (field->height + 1)));
	field->points_out = (t_point*)malloc(sizeof(t_point) * ((field->width + 1) * (field->height + 1)));
	field->points_mem = ft_peresapis(field, head);
	field->current = (t_curr*)malloc(sizeof(*(field->current))); //чутка разобраться
	fdf_points_copy(field);
	close(*fd);
	return (1);
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
		w1 = 1;
		list_p = list_p->next_p;
		w = field->width;
		step[2] += step[0];
		x = step[1];
		h--;
	}
	return (field->points_mem);
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
		list->points[i].color = fdf_find_color(array[i - 1]);
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
