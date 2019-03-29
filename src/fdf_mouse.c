/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 20:52:06 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/29 21:23:54 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_mouse_press(int button, int x, int y, t_field *fdf)
{
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
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

int 		fdf_mouse_release(int button, int x, int y, void *param)
{
	{
		printf("%d %d\n", x, y);
		y *= 4;     //это штука тоже непонятно как работает, потому что я писала, я в шоке
		x *= 4;
	}
	return (0);
}

int			fdf_mouse_move(int x, int y, void *param)
{
	{
		printf("%d %d\n", x, y);
		y *= 4;     //это штука тоже непонятно как работает, потому что я писала, я в шоке
		x *= 4;
	}
	return (0);
}
