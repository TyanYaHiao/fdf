/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 20:52:06 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/01 19:54:58 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_mouse_press(int button, int x, int y, t_field *fdf)
{
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN || button == MOUSE_BUTTON_MID)
	{
		if (button == MOUSE_BUTTON_MID)
			fdf->control->mouse_button_mid = TRUE;
		else
		{
			mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
			if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
			{
				if (button == MOUSE_SCROLL_UP)
				{
					fdf->offset_x -= ((x - WINDOW_W / 2) / 3);
					fdf->offset_y -= ((y - WINDOW_H / 2) / 3);
				}
				if (button == MOUSE_SCROLL_DOWN)
				{
					fdf->offset_x -= ((x - WINDOW_W / 2) / 10);
					fdf->offset_y -= ((y - WINDOW_H / 2) / 10);
				}
				fdf_scale_image(MOUSE, button, fdf);
			}
		}
	}
}

void		fdf_mouse_release(int button, int x, int y, t_field *fdf)
{
	if (button == MOUSE_BUTTON_MID)
	{
		fdf->control->mouse_button_mid = FALSE;
		fdf->control->prev_y = 0;
		fdf->control->prev_x = 0;
	}
}

void		fdf_mouse_move(int x, int y, t_field *fdf)
{
	if (fdf->control->mouse_button_mid == TRUE)
	{
		if (fdf->control->prev_x == 0)
			fdf->control->prev_x = x;
		if (fdf->control->prev_y == 0)
			fdf->control->prev_y = y;
		if (fdf->control->key_shift == FALSE && fdf->control->key_ctrl == FALSE)
		{
			fdf->angle_y -= ANGLE_STEP * (x - fdf->control->prev_x) / 10;
			fdf->angle_x -= ANGLE_STEP * (y - fdf->control->prev_y) / 10;
			fdf->control->prev_x = x;
			fdf->control->prev_y = y;
		}
		if (fdf->control->key_ctrl == TRUE && fdf->control->key_shift == FALSE)
		{
			fdf->offset_x += x - fdf->control->prev_x;
			fdf->offset_y += y - fdf->control->prev_y;
			fdf->control->prev_x = x;
			fdf->control->prev_y = y;
		}
		if (fdf->control->key_shift == TRUE && fdf->control->key_ctrl == FALSE)
		{
			fdf->angle_z += ANGLE_STEP * (y - fdf->control->prev_y) / 100;
			fdf->control->prev_x = x;
		}
		mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
		fdf_points_copy(fdf);
		fdf_evaluate(fdf);
		fdf_center_image(fdf);
		fdf_plot_image(fdf);
	}
}
