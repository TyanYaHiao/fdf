/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:37:23 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/24 20:06:22 by fsmith           ###   ########.fr       */
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
			(*fdf).points[i].x *= 2;
			(*fdf).points[i].y *= 2;
		}
		fdf_plot_image(*fdf);
	}
	else if (keycode == 78)
	{
		while (i++ < (*fdf).width * (*fdf).height)
		{
			(*fdf).points[i].x /= 2;
			(*fdf).points[i].y /= 2;
		}
		fdf_plot_image(*fdf);
	}
}

void		fdf_move_x(int keycode, t_field *fdf)
{
	int 	i;

	i = 0;
	if (keycode == 124)
	{
		while (i++ < (*fdf).width * (*fdf).height)
			(*fdf).points[i].x += MOVE_STEP_X;
		fdf_plot_image(*fdf);
	}
	else if (keycode == 123)
	{
		while (i++ < (*fdf).width * (*fdf).height)
			(*fdf).points[i].x -= MOVE_STEP_X;
		fdf_plot_image(*fdf);
	}
}

void		fdf_move_y(int keycode, t_field *fdf)
{
	int 	i;

	i = 0;
	if (keycode == 125)
	{
		while (i++ < (*fdf).width * (*fdf).height)
			(*fdf).points[i].y += MOVE_STEP_Y;
		fdf_plot_image(*fdf);
	}
	else if (keycode == 126)
	{
		while (i++ < (*fdf).width * (*fdf).height)
			(*fdf).points[i].y -= MOVE_STEP_Y;
		fdf_plot_image(*fdf);
	}
}

void		fdf_plot_isometry(int keycode, t_field *fdf)
{
	/* keycode not used now */
	t_field	temp_field;
	int		i;

	fdf->angle_x = 0.523599;
	temp_field = fdf_field_copy(*fdf);
	i = 0;
	printf("x = %f\ny = %f\n", (*fdf).points[34].x, (*fdf).points[34].y);
	while (i++ < fdf->width * fdf->height)
		fdf_isometry(&temp_field.points[i].x, &temp_field.points[i].y,
				temp_field.points[i].z, 0.523599);
	printf("x = %f\ny = %f\n", (*fdf).points[34].x, (*fdf).points[34].y);
	fdf_center_image(&temp_field);
	printf("x = %f\ny = %f\n", (*fdf).points[34].x, (*fdf).points[34].y);
//	printf("x = %f\ny = %f\n", (*fdf).points[1].x, (*fdf).points[1].y);
	fdf_plot_image(temp_field);
}

void		fdf_rotate_x(int keycode, t_field *fdf)
{
	t_field	temp_field;
	int 	i;

	if (keycode == 84)
		fdf->angle_x -= 0.01;
	else
		fdf->angle_x += 0.01;
	temp_field = fdf_field_copy(*fdf);
	i = 0;
	while (i++ < fdf->width * fdf->height)
		fdf_rotate_x_eval(&temp_field.points[i].x, &temp_field.points[i].y,
						  &temp_field.points[i].z, temp_field.angle_x);
	fdf_center_image(&temp_field);
	fdf_plot_image(temp_field);
}

void		fdf_rotate_y(int keycode, t_field *fdf)
{
	t_field	temp_field;
	int 	i;

	if (keycode == 86)
		fdf->angle_y -= 0.01;
	else
		fdf->angle_y += 0.01;
	temp_field = fdf_field_copy(*fdf);
	i = 0;
	while (i++ < fdf->width * fdf->height)
		fdf_rotate_y_eval(&temp_field.points[i].x, &temp_field.points[i].y,
						  &temp_field.points[i].z, temp_field.angle_y);
	fdf_center_image(&temp_field);
	fdf_plot_image(temp_field);
}

void		fdf_rotate_z(int keycode, t_field *fdf)
{
	t_field	temp_field;
	int 	i;

	if (keycode == 83)
		fdf->angle_z += 0.01;
	else
		fdf->angle_z -= 0.01;
	temp_field = fdf_field_copy(*fdf);
	i = 0;
	while (i++ < fdf->width * fdf->height)
		fdf_rotate_z_eval(&temp_field.points[i].x, &temp_field.points[i].y,
				&temp_field.points[i].z, temp_field.angle_z);
	fdf_center_image(&temp_field);
	fdf_plot_image(temp_field);
}

void		fdf_move_to_center(t_field *fdf)
{
	fdf_center_image(fdf);
	fdf_plot_image(*fdf);
}

void 		fdf_move_key(int keycode, t_field *fdf)
{
	int i = 0;

	/* Clear window probably need to move inside move functions */
	if (keycode == 34 || keycode == 49 || keycode == 53 || keycode == 69
		|| keycode == 78 || keycode == 83 || keycode == 84 || keycode == 86
		|| keycode == 88 || keycode == 91 || keycode == 92 || keycode == 123
		|| keycode == 124 || keycode == 125 || keycode == 126)
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
		if (keycode == 53)
			exit(0);
		if (keycode == 84 || keycode == 91)
			fdf_rotate_x(keycode, fdf);
		if (keycode == 86 || keycode == 88)
			fdf_rotate_y(keycode, fdf);
		if (keycode == 83 || keycode == 92)
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
			(*fdf).points[i].x *= 2;
		fdf_plot_image(*fdf);
	}
	if (button == 2)
	{
		while (i++ < (*fdf).width * (*fdf).height)
			(*fdf).points[i].x /= 2;
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
