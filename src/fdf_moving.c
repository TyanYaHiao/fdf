/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_moving.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:36:40 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/12 20:10:13 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_move(int mode, int keycode, t_field *fdf)
{
	if (mode == KEYBOARD)
	{
		if (keycode == KEY_NUM_RIGHT)
			fdf->offset_x += MOVE_STEP_X;
		else if (keycode == KEY_NUM_LEFT)
			fdf->offset_x -= MOVE_STEP_X;
		else if (keycode == KEY_NUM_DOWN)
			fdf->offset_y += MOVE_STEP_Y;
		else if (keycode == KEY_NUM_UP)
			fdf->offset_y -= MOVE_STEP_Y;
	}
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
	fdf_center_image(fdf);
	fdf_plot_image(fdf);
}

void		fdf_change_depth(int keycode, t_field *fdf)
{
	if (keycode == KEY_Z)
		fdf->coeff_z += 1;
	else if (keycode == KEY_X)
		fdf->coeff_z -= 1;
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
	fdf_center_image(fdf);
	fdf_plot_image(fdf);
}

void		fdf_scale_image(int mode, int keycode, t_field *fdf)
{
	if ((mode == KEYBOARD && keycode == KEY_PLUS)
	|| (mode == MOUSE && keycode == MOUSE_SCROLL_UP))
		fdf->scale *= 1.2;
	else if ((mode == KEYBOARD && keycode == KEY_MINUS)
	|| (mode == MOUSE && keycode == MOUSE_SCROLL_DOWN))
		fdf->scale /= 1.2;
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
	fdf_center_image(fdf);
	fdf_plot_image(fdf);
}

void		fdf_center_image(t_field *field)
{
	int		i;
	int		step_x;
	int		step_y;

	step_y = (int)((WINDOW_H - (field->points_out[field->width *\
		field->height].y - field->points_out[1].y)) / 2 -\
		field->points_out[1].y);
	step_x = (int)((WINDOW_W - (field->points_out[field->width *\
		field->height].x - field->points_out[1].x)) / 2 -\
		field->points_out[1].x);
	i = 0;
	while (i++ < field->width * field->height)
	{
		(*field).points_out[i].x += step_x + field->offset_x;
		(*field).points_out[i].y += step_y + field->offset_y;
	}
}
