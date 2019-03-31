/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:35:13 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/31 18:45:12 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_rotate(int mode, int keycode, t_field *fdf)
{
	if (mode == KEYBOARD)
	{
		if (keycode == KEY_NUM_2)
			fdf->angle_x -= ANGLE_STEP;
		else if (keycode == KEY_NUM_8)
			fdf->angle_x += ANGLE_STEP;
		else if (keycode == KEY_NUM_4)
			fdf->angle_y -= ANGLE_STEP;
		else if (keycode == KEY_NUM_6)
			fdf->angle_y += ANGLE_STEP;
		else if (keycode == KEY_NUM_1 || keycode == KEY_NUM_7)
			fdf->angle_z += ANGLE_STEP;
		else if (keycode == KEY_NUM_3 || keycode == KEY_NUM_9)
			fdf->angle_z -= ANGLE_STEP;
	}
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
	fdf_center_image(fdf);
	fdf_plot_image(fdf);
}
