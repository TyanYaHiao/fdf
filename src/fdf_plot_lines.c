/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <mlurker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:56:02 by mlurker           #+#    #+#             */
/*   Updated: 2019/03/17 19:23:05 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_delta(int x1, int x0)
{
	int 	res;

	res = x1 - x0;
	return (res);
}

void	plot_line_low(t_point *map, int i, int j)
{
	int delx = ft_abs1(map[j].x0, map[i].x0);
	int dely = ft_abs1(map[j].y0, map[i].y0);
	int D;
	int y;
	int yi = 1;
	if (dely < 0)
	{
		yi = -1;
		dely *= -1;
	}
	D = 2 * dely - delx;
	while (map[i].x0 <= map[j].x0)
	{
//		mlx_string_put(map[0].mlx_ptr, map[0].win_ptr, 500, 200, 0xafeeee, "check");
		mlx_pixel_put(map[0].mlx_ptr, map[0].win_ptr, map[i].x0, map[i].y0, 0xafeeee);
		if (D > 0)
		{
			map[i].y0 += yi;
			D -= 2 * delx;
		}
		D += 2 * dely;
		map[i].x0++;
	}
}


void	plot_line_high(t_point *map, int i, int j)
{
	int delx = ft_abs1(map[j].x0, map[i].x0);
	int dely = ft_abs1(map[j].y0, map[i].y0);
	int D;
	int xi = 1;
	if (delx < 0)
	{
		xi = -1;
		delx *= -1;
	}
	D = 2 * delx - dely;
	while (map[i].y0 <= map[j].y0)
	{
		mlx_string_put(map[0].mlx_ptr, map[0].win_ptr, 600, 200, 0x6b8e23, "check1");
		mlx_pixel_put(map[0].mlx_ptr, map[0].win_ptr, map[i].x0, map[i].y0, 0x6b8e23);
		if (D > 0)
		{
			map[i].x0 += xi;
			D -= 2 * dely;
		}
		D += 2 * delx;
		map[i].y0++;
	}
}

void	plot_line(t_point *map, int i, int j) // модифицированный алгоритм отрисовки линий
{
	int delx = ft_abs1(map[j].x0, map[i].x0);
	int dely = ft_abs1(map[j].y0, map[i].y0);
	if (dely < delx)
	{
		if (map[i].x0 > map[j].x0)
			plot_line_low(map, j, i);
		else
			plot_line_low(map, i, j);
	}
	else
	{
		if (map[i].y0 > map[i + 1].y0)
			plot_line_high(map, j, i);
		else
			plot_line_high(map, i, j);
	}
}

void	connect_pxl(t_field field, int i)
{
	if ((i % field->width) == 0)
		plot_line(field->points, i, i + field->width);
	else if ((i % field->height) == 0)
		plot_line(field->points, i, i + 1);
	else
	{
		plot_line(field->points, i, i + field->width);
		plot_line(field->points, i, i + 1);
	}
}
