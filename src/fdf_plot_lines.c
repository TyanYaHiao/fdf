/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <mlurker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:56:02 by mlurker           #+#    #+#             */
/*   Updated: 2019/03/17 21:56:44 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_delta(int x1, int x0)
{
	int 	res;

	res = x1 - x0;
	return (res);
}

void	plot_line_low(t_field field, t_point *map, int i, int j)
{
	int delx = ft_delta(map[j].x, map[i].x);
	int dely = ft_delta(map[j].y, map[i].y);
	int D;
	int y;
	int yi = 1;
	if (dely < 0)
	{
		yi = -1;
		dely *= -1;
	}
	D = 2 * dely - delx;
	while (map[i].x <= map[j].x)
	{
//		mlx_string_put(map[0].mlx_ptr, map[0].win_ptr, 500, 200, 0xafeeee, "check");
		mlx_pixel_put(field.mlx_ptr, field.win_ptr, map[i].x, map[i].y, 0xafeeee);
		if (D > 0)
		{
			map[i].y += yi;
			D -= 2 * delx;
		}
		D += 2 * dely;
		map[i].x++;
	}
}


void	plot_line_high(t_field field, t_point *map, int i, int j)
{
	int delx = ft_delta(map[j].x, map[i].x);
	int dely = ft_delta(map[j].y, map[i].y);
	int D;
	int xi = 1;
	if (delx < 0)
	{
		xi = -1;
		delx *= -1;
	}
	D = 2 * delx - dely;
	while (map[i].y <= map[j].y)
	{
		mlx_string_put(field.mlx_ptr, field.win_ptr, 600, 200, 0x6b8e23, "check1");
		mlx_pixel_put(field.mlx_ptr, field.win_ptr, map[i].x, map[i].y, 0x6b8e23);
		if (D > 0)
		{
			map[i].x += xi;
			D -= 2 * dely;
		}
		D += 2 * delx;
		map[i].y++;
	}
}

void	plot_line(t_field field, t_point *map, int i, int j) // модифицированный алгоритм отрисовки линий
{
	int delx = ft_delta(map[j].x, map[i].x);
	int dely = ft_delta(map[j].y, map[i].y);
	if (dely < delx)
	{
		if (map[i].x > map[j].x)
			plot_line_low(field, map, j, i);
		else
			plot_line_low(field, map, i, j);
	}
	else
	{
		if (map[i].y > map[i + 1].y)
			plot_line_high(field, map, j, i);
		else
			plot_line_high(field, map, i, j);
	}
}

void	connect_pxl(t_field field, int i)
{
	if ((i % field.width) == 0)
		plot_line(field, field.points, i, i + field.width);
	else if ((i % field.height) == 0)
		plot_line(field, field.points, i, i + 1);
	else
	{
		plot_line(field, field.points, i, i + field.width);
		plot_line(field, field.points, i, i + 1);
	}
}
