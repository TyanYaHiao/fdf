/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <mlurker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:56:02 by mlurker           #+#    #+#             */
/*   Updated: 2019/03/22 21:32:54 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double ft_abs2(double x0, double x1)
{
	double d = x1 - x0;
	if (d < 0)
		return (-1 * d);
	return (d);
}

void line(t_field field, t_point *map, int i, int j)
{
	double dx = ft_abs2(map[j].x, map[i].x);
	double dy = ft_abs2(map[j].y, map[i].y);
	double sx = 1;
	double sy = 1;
	if (map[i].x > map[j].x)
		sx = -1;
	if (map[i].y > map[j].y)
		sy = -1;
	double err = (dx>dy ? dx : -dy)/2, e2;

	double x1 = map[i].x;
	double y1 = map[i].y;
	for(;;){
		mlx_pixel_put(field.mlx_ptr, field.win_ptr, (int)x1, (int)y1, field.points[i].color);
		if (x1==map[j].x && y1==map[j].y) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; x1 += sx; }
		if (e2 < dy) { err += dx; y1 += sy; }
	}


}

void	plot_line(t_field field, t_point *map, int i, int j) // модифицированный алгоритм отрисовки линий (брезенхема)
{
	double delx = DELTA(map[j].x, map[i].x); // написала дифайн для нахождения дельты иксов
	double dely = DELTA(map[j].y, map[i].y);
	if (dely < delx) // проверки на то, кто где стоит, чтобы праивльно рисовать линию и передавать агументы в нужном порядке
	{
		if (map[i].x > map[j].x)
			line(field, map, j, i);
		else
			line(field, map, i, j); // вниз вправо
	}
	else
	{
		if (map[i].y > map[j].y)
			line(field, map, j, i);
		else
			line(field, map, i, j); // вниз влево
	}
}

void	connect_pxl(t_field field, int i)
{
	if (i % (field.width * field.height) != 0) // если это не последняя точку, то от нее нужно рисовать линии
	{
		if ((field.height) * (field.width) - i < field.width) // проверка на нижние точки
			plot_line(field, field.points, i, i + 1); // если это они, то рисуем только вбок
		else if ((i % (field.width)) == 0 && i != 0) // проверка на боковые точки
			plot_line(field, field.points, i, i + field.width); // если это они, то рисуем только вниз
		else // если не крайние точки рисуем :
		{
			plot_line(field, field.points, i, i + field.width); // вниз
			plot_line(field, field.points, i, i + 1); // вбок
		}
	}
}
