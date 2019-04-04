/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 21:35:56 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/02 17:43:19 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_plot_menu_line(t_field field, int start, int end)
{
	double dx = ft_abs_double(field.menu.corner[start].x, field.menu.corner[end].x);
	double dy = ft_abs_double(field.menu.corner[start].y, field.menu.corner[end].y);
	int sx = 1;
	int sy = 1;
	double	err;
	double x = field.menu.corner[start].x;
	double y = field.menu.corner[start].y;
	double e2;

	if (field.menu.corner[start].x > field.menu.corner[end].x)
		sx = -1;
	if (field.menu.corner[start].y > field.menu.corner[end].y)
		sy = -1;
	if (dx > dy)
		err = dx / 2;
	else
		err = -(dy) / 2;
	while (x != field.menu.corner[end].x || y != field.menu.corner[end].y)
	{
		mlx_pixel_put(field.mlx_ptr, field.win_ptr, (int) x, (int) y, field.menu.color);
		e2 = err;
		if (e2 > -(dx))
		{
			err -= dy;
			x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y += sy;
		}
	}
}

void		fdf_plot_menu(t_field field)
{
	int i = 0;

	while (i < 3)
	{
		fdf_plot_menu_line(field, i, i + 1);
		i++;
	}
	fdf_plot_menu_line(field, 3, 0);
}

void		fdf_menu_init(t_menu *menu)
{
	menu->width = 400;
	menu->height = 200;
	menu->corner = (t_curr*)malloc(sizeof(t_curr) * 4);
	menu->corner[0].x = 30;
	menu->corner[0].y = 30;
	menu->corner[1].x = menu->corner[0].x + menu->width;
	menu->corner[1].y = menu->corner[0].y;
	menu->corner[2].x = menu->corner[0].x + menu->width;
	menu->corner[2].y = menu->corner[0].y + menu->height;
	menu->corner[3].x = menu->corner[0].x;
	menu->corner[3].y = menu->corner[0].y + menu->height;
	menu->color = DEFAULT_COLOR;
	menu->name = "menu";
}
