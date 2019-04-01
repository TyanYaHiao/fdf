/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_field.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 15:20:23 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/01 14:35:20 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			fdf_field_init(t_field *initiated_field)
{
	initiated_field->height = 0;
	initiated_field->width = 0;
	initiated_field->scale = 0;
	initiated_field->angle_x = 0;
	initiated_field->angle_y = 0;
	initiated_field->angle_z = 0;
	initiated_field->offset_x = 0;
	initiated_field->offset_y = 0;
	initiated_field->scale = 1;
	initiated_field->coeff_z = Z_COEFF;
	initiated_field->control = (t_control*)malloc(sizeof(t_control));
	initiated_field->control->prev_x = 0;
	initiated_field->control->prev_y = 0;
	initiated_field->control->mouse_button_mid = FALSE;
	initiated_field->control->key_shift = FALSE;
	initiated_field->control->key_ctrl = FALSE;
	initiated_field->mlx_ptr = mlx_init();
	initiated_field->win_ptr = mlx_new_window(initiated_field->mlx_ptr,
			WINDOW_W, WINDOW_H, "Fil de Fer");
//	initiated_field->img_ptr = mlx_new_image(initiated_field->mlx_ptr, WINDOW_W, WINDOW_H);
//	initiated_field->image = (int*)mlx_get_data_addr(initiated_field->img_ptr, &initiated_field->bpp, &initiated_field->s_line, &initiated_field->endian);
//	initiated_field->bpp /= 4;
}

void			fdf_points_copy(t_field *field)
{
	int 		i;

	i = 0;
	while (i < (field->width + 1) * (field->height + 1))
	{
		field->points_out[i] = field->points_mem[i];
		i++;
	}
}

void			fdf_field_info(t_field field)
{
	mlx_string_put(field.mlx_ptr, field.win_ptr, 10, 10, TEXT_COLOR, field.map_name);
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 150, 10, TEXT_COLOR, "Offset x:");
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 60, 10, TEXT_COLOR, ft_itoa(field.offset_x));
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 150, 30, TEXT_COLOR, "Offset y:");
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 60, 30, TEXT_COLOR, ft_itoa(field.offset_y));
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 150, 50, TEXT_COLOR, "Scale:");
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 60, 50, TEXT_COLOR, ft_itoa(field.scale * 100));
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 150, 70, TEXT_COLOR, "Deepness:");
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 60, 70, TEXT_COLOR, ft_itoa(-field.coeff_z));
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 150, 90, TEXT_COLOR, "X angle:");
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 60, 90, TEXT_COLOR, ft_itoa(field.angle_x * 180 / M_PI));
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 150, 110, TEXT_COLOR, "Y angle:");
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 60, 110, TEXT_COLOR, ft_itoa(field.angle_y * 180 / M_PI));
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 150, 130, TEXT_COLOR, "Z angle:");
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 60, 130, TEXT_COLOR, ft_itoa(field.angle_z * 180 / M_PI));
}