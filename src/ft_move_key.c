/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:37:23 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/25 20:11:13 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_scale_image(int keycode, t_field *fdf)
{
	int 	i;

	i = 0;
	if (keycode == 69)
	{
		while (i++ < (*fdf).width * (*fdf).height)
		{
			(*fdf).points_mem[i].x *= 2;
			(*fdf).points_mem[i].y *= 2;
		}
		fdf_plot_image(*fdf);
	}
	else if (keycode == 78)
	{
		while (i++ < (*fdf).width * (*fdf).height)
		{
			(*fdf).points_mem[i].x /= 2;
			(*fdf).points_mem[i].y /= 2;
		}
		fdf_plot_image(*fdf);
	}
}

void 		fdf_move_key(int keycode, t_field *fdf)
{
	int i = 0;

	/* Clear window probably need to move inside move functions */
	if (keycode == 17 || keycode == 34 || keycode == 49 || keycode == 53 || keycode == 69
		|| keycode == 78 || keycode == 83 || keycode == 84 || keycode == 85
		|| keycode == 86 || keycode == 88 || keycode == 89 || keycode == 91
		|| keycode == 92 || keycode == 123 || keycode == 124
		|| keycode == 125 || keycode == 126)
	{
		mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
		if (keycode == 124 || keycode == 123)
			fdf_move_x(keycode, fdf);
		if (keycode == 125 || keycode == 126)
			fdf_move_y(keycode, fdf);
		if (keycode == 69 || keycode == 78)
			fdf_scale_image(keycode, fdf);
		if (keycode == 49)
			fdf_move_to_center(fdf);
		if (keycode == 34)
			fdf_plot_isometry(keycode, fdf);
		if (keycode == 17)
			fdf_plot_top_view(keycode, fdf);
		if (keycode == 53)
			exit(0);
		if (keycode == 84 || keycode == 91)
			fdf_rotate_x(keycode, fdf);
		if (keycode == 86 || keycode == 88)
			fdf_rotate_y(keycode, fdf);
		if (keycode == 83 || keycode == 85 || keycode == 89 || keycode == 92)
			fdf_rotate_z(keycode, fdf);
	}
}

int mouse_press(int button, int x, int y, t_field *fdf)
{
	int i = 0;
	mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
	if (button == 1)
	{
		while (i++ < (*fdf).width * (*fdf).height)
			(*fdf).points_mem[i].x *= 2;
		fdf_plot_image(*fdf);
	}
	if (button == 2)
	{
		while (i++ < (*fdf).width * (*fdf).height)
			(*fdf).points_mem[i].x /= 2;
		fdf_plot_image(*fdf);
	}
//	printf("%d %d\n", x, y);
	// я хз что это, можешь посмотреть в кук буке для фдф (форум интры), я не разобралась
	return (0);
}

int event(int button, int x, int y, void *param)
{
	printf("%d %d\n", x, y); // это работает, потому что написала ксюша
	return (0);
}

int mouse_release(int button, int x, int y, void *param)
{
	{
		printf("%d %d\n", x, y);
		y *= 4;     //это штука тоже непонятно как работает, потому что я писала, я в шоке
		x *= 4;
	}
	return (0);
}
