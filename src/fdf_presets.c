/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_presets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:10:09 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/02 15:26:56 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_plot_isometry(int keycode, t_field *fdf)
{
	fdf->angle_x = 0.785398;
	fdf->angle_y = 0.610865;
	fdf->angle_z = 0.523599;
	fdf->offset_x = 0;
	fdf->offset_y = 0;
	fdf->scale = 1.2;
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
	fdf_center_image(fdf);
	fdf_plot_image(fdf);
}

void		fdf_plot_top_view(int keycode, t_field *fdf)
{
	fdf->angle_x = 0;
	fdf->angle_y = 0;
	fdf->angle_z = 0;
	fdf->offset_x = 0;
	fdf->offset_y = 0;
	fdf->scale = 1;
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
	fdf_center_image(fdf);
	fdf_plot_image(fdf);
}

void		fdf_plot_front_view(int keycode, t_field *fdf)
{
	fdf->angle_x = -M_PI / 2;
	fdf->angle_y = 0;
	fdf->angle_z = 0;
	fdf->offset_x = 0;
	fdf->offset_y = 0;
	fdf->scale = 1;
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
	fdf_center_image(fdf);
	fdf_plot_image(fdf);
}

void		fdf_plot_side_view(int keycode, t_field *fdf)
{
	fdf->angle_x = 0;
	fdf->angle_y = -M_PI / 2;
	fdf->angle_z = 0;
	fdf->offset_x = 0;
	fdf->offset_y = 0;
	fdf->scale = 1;
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
	fdf_center_image(fdf);
	fdf_plot_image(fdf);
}

void		fdf_move_to_center(t_field *fdf)
{
	fdf->offset_x = 0;
	fdf->offset_y = 0;
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
	fdf_center_image(fdf);
	fdf_plot_image(fdf);
}
