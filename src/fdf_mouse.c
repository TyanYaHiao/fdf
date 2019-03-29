/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 20:52:06 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/29 22:31:25 by fsmith           ###   ########.fr       */
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
					fdf->offset_x -= ((x - WINDOW_W / 2) / 7);
					fdf->offset_y -= ((y - WINDOW_H / 2) / 7);
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

void 		fdf_mouse_release(int button, int x, int y, t_field *fdf)
{
	if (button == MOUSE_BUTTON_MID)
	{
		printf("ТЫ ПИДОР!!");
		fdf->control->mouse_button_mid = FALSE;
	}
}

void		fdf_mouse_move(int button, int x, int y, t_field *fdf)
{
	if (fdf->control->mouse_button_mid == TRUE)
	{
		fdf->offset_x += (x - WINDOW_W / 2);
		fdf->offset_y += (y - WINDOW_H / 2);
		printf("ТЫ ПИДОР");
	}
}
