/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <mlurker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:56:02 by mlurker           #+#    #+#             */
/*   Updated: 2019/03/31 19:39:11 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double		percent(double start, double end, double current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			get_light(double start, double end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			get_color(t_field field, int start_index, int end_index)
{
	int     red;
	int     green;
	int     blue;
	double  percentage;

	if (field.current->color == END_POINT.color)
		return (field.current->color);
	if (field.current->dx > field.current->dy)
		percentage = percent(START_POINT.x, END_POINT.x, field.current->x);
	else
		percentage = percent(START_POINT.y, END_POINT.y, field.current->y);
	red = get_light((START_POINT.color >> 16) & 0xFF, (END_POINT.color >> 16) & 0xFF, percentage);
	green = get_light((START_POINT.color >> 8) & 0xFF, (END_POINT.color >> 8) & 0xFF, percentage);
	blue = get_light(START_POINT.color & 0xFF, END_POINT.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void		fdf_init_curr(t_field field, int start_index, int end_index)
{
	field.current->x = START_POINT.x;
	field.current->y = START_POINT.y;
	field.current->dx = ft_abs_double(END_POINT.x, START_POINT.x);
	field.current->dy = ft_abs_double(END_POINT.y, START_POINT.y);
	field.current->color = START_POINT.color;
	field.current->sx = 1;
	field.current->sy = 1;
	if (START_POINT.x > END_POINT.x)
		field.current->sx = -1;
	if (START_POINT.y > END_POINT.y)
		field.current->sy = -1;
}

void		fdf_set_line(t_field field, int start_index, int end_index)
{
	double 	err;
	double	e2;

	fdf_init_curr(field, start_index, end_index);
	if (field.current->dx > field.current->dy)
		err = field.current->dx / 2;
	else
		err = -(field.current->dy) / 2;
	while (field.current->x != END_POINT.x || field.current->y != END_POINT.y)
	{
		mlx_pixel_put(field.mlx_ptr, field.win_ptr, (int)field.current->x, (int)field.current->y,
				get_color(field, start_index, end_index));
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

void		fdf_plot_image(t_field *field)
{
	int 	i;

	i = 0;
	while (i++ < field->width * field->height)
	{
		if (i % (field->width * field->height) != 0) // если это не последняя точку, то от нее нужно рисовать линии
		{
			if ((field->height) * (field->width) - i < field->width) // проверка на нижние точки
				fdf_set_line(*field, i, i + 1); // если это они, то рисуем только вбок
			else if ((i % (field->width)) == 0 && i != 0) // проверка на боковые точки
				fdf_set_line(*field, i, i + field->width); // если это они, то рисуем только вниз
			else // если не крайние точки рисуем :
			{
				fdf_set_line(*field, i, i + field->width); // вниз
				fdf_set_line(*field, i, i + 1); // вбок
			}
		}
	}
	fdf_field_info(*field);
}
