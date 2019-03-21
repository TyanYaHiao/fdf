/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <mlurker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:56:02 by mlurker           #+#    #+#             */
/*   Updated: 2019/03/19 23:10:36 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	plot_line_low(t_field field, t_point *map, int i, int j)
{
	double delx = DELTA(map[j].x, map[i].x);
	double dely = DELTA(map[j].y, map[i].y);
	double D;
	double x1 = map[i].x;
	double y1 = map[i].y;
	double yi = 1;
	if (dely < 0)
	{
		yi = -1;
		dely *= -1;
	}
	D = 2 * dely - delx;
	while (x1 <= map[j].x)
	{
		mlx_pixel_put(field.mlx_ptr, field.win_ptr, x1, y1, 0xafeeee); // голубые линии
		if (D > 0)
		{
			y1 += yi;
			D -= 2 * delx;
		}
		D += 2 * dely;
		x1++;
	}
}

void	plot_line_high(t_field field, t_point *map, int i, int j) // алгоритм брезенхема с вики
{
	double delx = DELTA(map[j].x, map[i].x);
	double dely = DELTA(map[j].y, map[i].y);
	double D;
	double x1 = map[i].x;
	double y1 = map[i].y;
	double xi = 1;
	if (delx < 0)
	{
		xi = -1;
		delx *= -1;
	}
	D = 2 * delx - dely;
	while (y1 <= map[j].y)
	{
		mlx_pixel_put(field.mlx_ptr, field.win_ptr, x1, y1, 0x6b8e23); // зеленые линии
		if (D > 0)
		{
			x1 += xi;
			D -= 2 * dely;
		}
		D += 2 * delx;
		y1++;
	}
}

void	plot_line(t_field field, t_point *map, int i, int j) // модифицированный алгоритм отрисовки линий (брезенхема)
{
	double delx = DELTA(map[j].x, map[i].x); // написала дифайн для нахождения дельты иксов
	double dely = DELTA(map[j].y, map[i].y);
	if (dely < delx) // проверки на то, кто где стоит, чтобы праивльно рисовать линию и передавать агументы в нужном порядке
	{
		if (map[i].x > map[j].x)
			plot_line_low(field, map, j, i);
		else
			plot_line_low(field, map, i, j); // вниз вправо
	}
	else
	{
		if (map[i].y > map[j].y)
			plot_line_high(field, map, j, i);
		else
			plot_line_high(field, map, i, j); // вниз влево
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

//void	plot(t_field field, int i, int j)
//{
//	double x1 = field.points[i].x;
//	double x2 = field.points[j].x;
//	double y1 = field.points[i].y;
//	double y2 = field.points[j].y;
//
//	if (x2 < x1)
//	{
//		x1 = field.points[j].x;
//		x2 = field.points[i].x;
//		y1 = field.points[j].y;
//		y2 = field.points[i].y;
//	}
//	double dx = DELTA(x2, x1);
//	double dy = DELTA(y2, y1);
//	double grad = dy / dy;

//}
