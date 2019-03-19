/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <mlurker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:56:02 by mlurker           #+#    #+#             */
/*   Updated: 2019/03/19 21:24:10 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double		ft_delta(double x1, double x0)
{
	return (x1 - x0);
}


void	plot_line_low(t_field field, t_point *map, int i, int j)
{
	double delx = ft_delta(map[j].x, map[i].x);
	double dely = ft_delta(map[j].y, map[i].y);
	double D;
	double x1 = map[i].x;
	double y1 = map[i].y;
	double x2 = map[j].x;
	double y2 = map[j].y;
	double yi = 1;
	if (dely < 0)
	{
		yi = -1;
		dely *= -1;
	}
	D = 2 * dely - delx;
	while (x1 <= x2)
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

void	plot_line_high(t_field field, t_point *map, int i, int j)
{
	double delx = ft_delta(map[j].x, map[i].x);
	double dely = ft_delta(map[j].y, map[i].y);
	double D;
	double x1 = map[i].x;
	double y1 = map[i].y;
	double x2 = map[j].x;
	double y2 = map[j].y;
	double xi = 1;
	if (delx < 0)
	{
		xi = -1;
		delx *= -1;
	}
	D = 2 * delx - dely;
	while (y1 <= y2)
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

void	plot_line(t_field field, t_point *map, int i, int j, int check) // модифицированный алгоритм отрисовки линий
{
	double delx = ft_delta(map[j].x, map[i].x);
	double dely = ft_delta(map[j].y, map[i].y);
	if (dely < delx)
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

void	connect_pxl(t_field field, int i, int check)
{
	if (i % (field.width * field.height) != 0)
	{
		if ((field.height) * (field.width) - i < field.width)
			plot_line(field, field.points, i, i + 1, check);
		else if ((i % (field.width)) == 0 && i != 0)
			plot_line(field, field.points, i, i + field.width, check);
		else
		{
			plot_line(field, field.points, i, i + field.width, check);
			plot_line(field, field.points, i, i + 1, check);
		}
	}
}
