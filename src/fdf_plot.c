/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <mlurker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:56:02 by mlurker           #+#    #+#             */
/*   Updated: 2019/03/24 17:03:42 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double percent(double start, double end, double current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int get_light(double start, double end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(t_curr current, t_point start, t_point end)
{
	int     red;
	int     green;
	int     blue;
	double  percentage;

	if (current.color == end.color)
		return (current.color);
	if (current.dx > current.dy)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void fdf_init_curr(t_curr **current, t_point *map, int i, int j)
{
	(*current)->x = map[i].x;
	(*current)->y = map[i].y;
	(*current)->dx = ft_abs_double(map[j].x, map[i].x);
	(*current)->dy = ft_abs_double(map[j].y, map[i].y);
	(*current)->color = map[i].color;
	(*current)->sx = 1;
	(*current)->sy = 1;
	if (map[i].x > map[j].x)
		(*current)->sx = -1;
	if (map[i].y > map[j].y)
		(*current)->sy = -1;
}

void fdf_set_line(t_field field, t_point *map, int i, int j)
{
	fdf_init_curr(&field.current, map, i, j);
	double err = (field.current->dx > field.current->dy ? field.current->dx : -(field.current->dy)) / 2, e2;

	while (field.current->x != map[j].x || field.current->y != map[j].y)
	{
		mlx_pixel_put(field.mlx_ptr, field.win_ptr, (int)field.current->x, (int)field.current->y, get_color(*field.current, map[i], map[j]));
		e2 = err;
		if (e2 > -(field.current->dx))
		{
			err -= field.current->dy;
			field.current->x += field.current->sx;
		}
		if (e2 < field.current->dy)
		{
			err += field.current->dx;
			field.current->y += field.current->sy;
		}
	}
}

void	fdf_plot_image(t_field field)
{
	int i;

	i = 0;
	while (i++ < field.width * field.height)
	{
		if (i % (field.width * field.height) != 0) // если это не последняя точку, то от нее нужно рисовать линии
		{
			if ((field.height) * (field.width) - i < field.width) // проверка на нижние точки
				fdf_set_line(field, field.points_out, i, i + 1); // если это они, то рисуем только вбок
			else if ((i % (field.width)) == 0 && i != 0) // проверка на боковые точки
				fdf_set_line(field, field.points_out, i, i + field.width); // если это они, то рисуем только вниз
			else // если не крайние точки рисуем :
			{
				fdf_set_line(field, field.points_out, i, i + field.width); // вниз
				fdf_set_line(field, field.points_out, i, i + 1); // вбок
			}
		}
	}
	mlx_string_put(field.mlx_ptr, field.win_ptr, 10, 10, 0xcdcd, field.map_name);
	fdf_field_info(field);
}
