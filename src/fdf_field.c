/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_field.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 15:20:23 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/13 18:44:28 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			fdf_field_init(t_field *init_field)
{
	init_field->height = 0;
	init_field->width = 0;
	init_field->angle_x = 0;
	init_field->angle_y = 0;
	init_field->angle_z = 0;
	init_field->offset_x = 0;
	init_field->offset_y = 0;
	init_field->max_z = 0;
	init_field->min_z = 0;
	init_field->scale = 1;
	init_field->coeff_z = Z_COEFF;
	init_field->control = (t_control*)malloc(sizeof(t_control));
	init_field->control->prev_x = 0;
	init_field->control->prev_y = 0;
	init_field->control->mouse_button_mid = FALSE;
	init_field->control->key_shift = FALSE;
	init_field->control->key_ctrl = FALSE;
	init_field->control->help = FALSE;
	init_field->mlx_ptr = mlx_init();
	init_field->win_ptr = mlx_new_window(init_field->mlx_ptr,
		WINDOW_W, WINDOW_H, "Fil de Fer");
	init_field->img_ptr = mlx_new_image(init_field->mlx_ptr, WINDOW_W,
		WINDOW_H);
	init_field->image = mlx_get_data_addr(init_field->img_ptr,
		&init_field->bpp, &init_field->s_line, &init_field->endian);
}

void			fdf_points_copy(t_field *field)
{
	int			i;

	i = 0;
	while (i < (field->width + 1) * (field->height + 1))
	{
		field->points_out[i] = field->points_mem[i];
		i++;
	}
}
