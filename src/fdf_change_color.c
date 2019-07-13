/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_change_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <mlurker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:29:24 by mlurker           #+#    #+#             */
/*   Updated: 2019/07/13 18:44:23 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_change_color_rgb(int keycode, t_field *fdf)
{
	int		i;

	i = 0;
	if (keycode == KEY_R)
		while (++i < fdf->width * fdf->height)
		{
			if (fdf->points_mem[i].color != DEFAULT_COLOR)
				fdf->points_mem[i].color = 0xFF0000;
		}
	else if (keycode == KEY_G)
		while (++i < fdf->width * fdf->height)
		{
			if (fdf->points_mem[i].color != DEFAULT_COLOR)
				fdf->points_mem[i].color = 0x00FF00;
		}
	else if (keycode == KEY_B)
		while (++i < fdf->width * fdf->height)
		{
			if (fdf->points_mem[i].color != DEFAULT_COLOR)
				fdf->points_mem[i].color = 0x0000FF;
		}
}

void		fdf_color_on_height(t_field *fdf, int i)
{
	int		spectrum;
	int		delta;

	spectrum = (int)(fdf->max_z - fdf->min_z);
	if (spectrum != 0)
	{
		delta = (int)(fdf->max_z - fdf->points_mem[i].z);
		fdf->points_out[i].color = 0xFF0000 * delta / spectrum;
	}
}

void		fdf_change_color(int keycode, t_field *fdf)
{
	int		i;

	i = 1;
	if (keycode == KEY_R || keycode == KEY_G || keycode == KEY_B)
		fdf_change_color_rgb(keycode, fdf);
	else if (keycode == KEY_Q)
		fdf->color_shift++;
	else if (keycode == KEY_W)
		fdf->color_shift--;
	else if (keycode == KEY_E)
		fdf->color_height = !fdf->color_height;
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
	fdf_center_image(fdf);
	fdf_plot_image(fdf);
}

void		fdf_color_calc(int *color, int color_shift)
{
	int		alpha;
	int		red;
	int		green;
	int		blue;

	alpha = *color & 0xFF << 24;
	red = *color & 0xFF << 16;
	green = *color & 0xFF << 8;
	blue = *color & 0xFF;
	if ((abs(color_shift) % 3) == 1)
		*color = alpha | red >> 8 | green >> 8 | blue << 16;
	else if ((abs(color_shift) % 3) == 2)
		*color = alpha | red >> 16 | green << 8 | blue << 8;
}
