/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_change_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <mlurker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:29:24 by mlurker           #+#    #+#             */
/*   Updated: 2019/04/12 18:18:24 by mlurker          ###   ########.fr       */
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

void		fdf_change_color(int keycode, t_field *fdf)
{
	int		i;

	i = 1;
	if (keycode == KEY_R || keycode == KEY_G || keycode == KEY_B)
		fdf_change_color_rgb(keycode, fdf);
	else if (keycode == KEY_Q)
		while (++i < fdf->width * fdf->height)
		{
			if (fdf->points_mem[i].color != DEFAULT_COLOR)
				fdf->points_mem[i].color >>= 1;
		}
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
	fdf_center_image(fdf);
	fdf_plot_image(fdf);
}
