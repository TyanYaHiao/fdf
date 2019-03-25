/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_moving.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:36:40 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/25 22:04:19 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_move(int keycode, t_field *fdf)
{
	if (keycode == 124)
		fdf->offset_x += MOVE_STEP_X;
	else if (keycode == 123)
		fdf->offset_x -= MOVE_STEP_X;
	else if (keycode == 125)
		fdf->offset_y += MOVE_STEP_Y;
	else if (keycode == 126)
		fdf->offset_y -= MOVE_STEP_Y;
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
	fdf_center_image(fdf);
//	printf("move: x = %f__y = %f\n", (*fdf).points[40].x, (*fdf).points[40].y);
//	printf("movestep: x = %d__y = %d\n", fdf->offset_x, fdf->offset_y);
	fdf_plot_image(*fdf);
}

void		fdf_change_depth(int keycode, t_field *fdf)
{
	if (keycode == 6)
		fdf->coeff_z += 1;
	else if (keycode == 7)
		fdf->coeff_z -= 1;
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
	fdf_center_image(fdf);
	fdf_plot_image(*fdf);
}
