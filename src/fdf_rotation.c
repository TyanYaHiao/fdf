/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:35:13 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/25 19:47:03 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_rotate_x(int keycode, t_field *fdf)
{
	if (keycode == 84)
		fdf->angle_x -= ANGLE_STEP;
	else
		fdf->angle_x += ANGLE_STEP;
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
	fdf_center_image(fdf);
	fdf_plot_image(*fdf);
}

void		fdf_rotate_y(int keycode, t_field *fdf)
{
	if (keycode == 86)
		fdf->angle_y -= ANGLE_STEP;
	else
		fdf->angle_y += ANGLE_STEP;
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
	fdf_center_image(fdf);
	fdf_plot_image(*fdf);
}

void		fdf_rotate_z(int keycode, t_field *fdf)
{
	if (keycode == 83 || keycode == 89)
		fdf->angle_z += ANGLE_STEP;
	else
		fdf->angle_z -= ANGLE_STEP;
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
	fdf_center_image(fdf);
	fdf_plot_image(*fdf);
}

