/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:37:23 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/29 19:11:17 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void 		fdf_move_key(int keycode, t_field *fdf)
{
	/* Clear window probably need to move inside move functions */
	if (keycode == 6 || keycode == 7 || keycode == 17 || keycode == 34 || keycode == 49 || keycode == 53 ||
		keycode == 69 || keycode == 78 || keycode == 83 || keycode == 84 ||
		keycode == 85 || keycode == 86 || keycode == 88 || keycode == 89 ||
		keycode == 91 || keycode == 92 || keycode == 123 || keycode == 124 ||
		keycode == 125 || keycode == 126 || keycode == KEY_S || keycode == KEY_F || keycode == KEY_U)
	{
		mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
		if (keycode == KEY_NUM_LEFT || keycode == KEY_NUM_RIGHT || keycode == KEY_NUM_DOWN || keycode == KEY_NUM_UP)
			fdf_move(KEYBOARD, keycode, fdf);
		if (keycode == KEY_PLUS || keycode == KEY_MINUS)
			fdf_scale_image(KEYBOARD, keycode, fdf);
		if (keycode == KEY_SPACE)
			fdf_move_to_center(fdf);
		if (keycode == KEY_I)
			fdf_plot_isometry(keycode, fdf);
		if (keycode == KEY_U)
			fdf_real_isometry(keycode, fdf);
		if (keycode == KEY_T)
			fdf_plot_top_view(keycode, fdf);
		if (keycode == KEY_F)
			fdf_plot_front_view(keycode, fdf);
		if (keycode == KEY_S)
			fdf_plot_side_view(keycode, fdf);
		if (keycode == KEY_Z || keycode == KEY_X)
			fdf_change_depth(keycode, fdf);
		if (keycode == KEY_ESC)
			exit(0);
		if (keycode == KEY_NUM_1 || keycode == KEY_NUM_2 || keycode == KEY_NUM_3 || keycode == KEY_NUM_4
		|| keycode == KEY_NUM_6 || keycode == KEY_NUM_7 || keycode == KEY_NUM_8 || keycode == KEY_NUM_9)
			fdf_rotate(keycode, fdf);
	}
}

int event(int button, int x, int y, void *param)
{
	printf("%d %d\n", x, y); // это работает, потому что написала ксюша
	return (0);
}
