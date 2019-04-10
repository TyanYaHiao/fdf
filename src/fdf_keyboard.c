/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:37:23 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/10 21:32:17 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			fdf_keyboard_key_check(int keycode)
{
	if (keycode == KEY_ESC || keycode == KEY_SPACE ||
		keycode == KEY_MINUS || keycode == KEY_PLUS ||
		keycode == KEY_NUM_1 || keycode == KEY_NUM_2 || keycode == KEY_NUM_3 ||
		keycode == KEY_NUM_4 || keycode == KEY_NUM_6 || keycode == KEY_NUM_7 ||
		keycode == KEY_NUM_8 || keycode == KEY_NUM_9 ||
		keycode == KEY_NUM_LEFT || keycode == KEY_NUM_RIGHT ||
		keycode == KEY_NUM_UP || keycode == KEY_NUM_DOWN ||
		keycode == KEY_Z || keycode == KEY_X || keycode == KEY_T ||
		keycode == KEY_I || keycode == KEY_R || keycode == KEY_G ||
		keycode == KEY_B || keycode == KEY_Q || keycode == KEY_S ||
		keycode == KEY_F)
		return (1);
	return (0);
}

void		fdf_keyboard_key_letter(int keycode, t_field *fdf)
{
	if (keycode == KEY_I)
		fdf_plot_isometry(keycode, fdf);
	if (keycode == KEY_T)
		fdf_plot_top_view(keycode, fdf);
	if (keycode == KEY_F)
		fdf_plot_front_view(keycode, fdf);
	if (keycode == KEY_S)
		fdf_plot_side_view(keycode, fdf);
	if (keycode == KEY_Z || keycode == KEY_X)
		fdf_change_depth(keycode, fdf);
	if (keycode == KEY_B || keycode == KEY_G ||
		keycode == KEY_R || keycode == KEY_Q)
		fdf_change_color(keycode, fdf);
}

void		fdf_keyboard_press(int keycode, t_field *fdf)
{
	if (fdf_keyboard_key_check(keycode))
	{
		mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
		fdf_keyboard_key_letter(keycode, fdf);
		if (keycode == KEY_NUM_LEFT || keycode == KEY_NUM_RIGHT ||
		keycode == KEY_NUM_DOWN || keycode == KEY_NUM_UP)
			fdf_move(KEYBOARD, keycode, fdf);
		if (keycode == KEY_PLUS || keycode == KEY_MINUS)
			fdf_scale_image(KEYBOARD, keycode, fdf);
		if (keycode == KEY_SPACE)
			fdf_move_to_center(fdf);
		if (keycode == KEY_ESC)
			exit(0);
		if (keycode == KEY_NUM_1 || keycode == KEY_NUM_2 ||
		keycode == KEY_NUM_3 || keycode == KEY_NUM_4
		|| keycode == KEY_NUM_6 || keycode == KEY_NUM_7 ||
		keycode == KEY_NUM_8 || keycode == KEY_NUM_9)
			fdf_rotate(KEYBOARD, keycode, fdf);
	}
	if (keycode == KEY_CTRL_LEFT)
		fdf->control->key_ctrl = TRUE;
	if (keycode == KEY_SHIFT_LEFT)
		fdf->control->key_shift = TRUE;
}

void		fdf_keyboard_release(int keycode, t_field *fdf)
{
	if (keycode == KEY_CTRL_LEFT)
	{
		fdf->control->key_ctrl = FALSE;
		fdf->control->prev_y = 0;
		fdf->control->prev_x = 0;
	}
	if (keycode == KEY_SHIFT_LEFT)
	{
		fdf->control->key_shift = FALSE;
		fdf->control->prev_y = 0;
		fdf->control->prev_x = 0;
	}
}
