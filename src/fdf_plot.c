/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <mlurker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:56:02 by mlurker           #+#    #+#             */
/*   Updated: 2019/04/12 18:18:24 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_set_line(t_field field, int start, int end)
{
	double	err;
	double	e2;

	fdf_init_curr(field, start, end);
	err = -(field.current->dy) / 2;
	if (field.current->dx > field.current->dy)
		err = field.current->dx / 2;
	while (field.current->x != END_POINT.x || field.current->y != END_POINT.y)
	{
		if (field.current->x >= 0 && field.current->x < WINDOW_W
		&& field.current->y >= 0 && field.current->y < WINDOW_H)
			*(int*)(field.image + (int)field.current->x * 4 +
			(int)field.current->y * field.s_line) = color(field, start, end);
		e2 = err;
		if (e2 > -(field.current->dx))
		{
			err -= field.current->dy;
			field.current->x += field.current->sx;
		}
		if (e2 < field.current->dy)
		{
			err += field.current->dx;
			field.current->y += field.current->sy;
		}
	}
}

void		fdf_plot_image(t_field *field)
{
	int		i;

	mlx_clear_window(field->mlx_ptr, field->win_ptr);
	field->img_ptr = mlx_new_image(field->mlx_ptr, WINDOW_W, WINDOW_H);
	field->image = mlx_get_data_addr(field->img_ptr, &field->bpp,
			&field->s_line, &field->endian);
	i = 0;
	while (i++ < field->width * field->height)
		if (i % (field->width * field->height) != 0)
		{
			if ((field->height) * (field->width) - i < field->width)
				fdf_set_line(*field, i, i + 1);
			else if ((i % (field->width)) == 0 && i != 0)
				fdf_set_line(*field, i, i + field->width);
			else
			{
				fdf_set_line(*field, i, i + field->width);
				fdf_set_line(*field, i, i + 1);
			}
		}
	mlx_put_image_to_window(field->mlx_ptr, field->win_ptr,
			field->img_ptr, 0, 0);
	mlx_destroy_image(field->mlx_ptr, field->img_ptr);
	fdf_field_info(*field);
}
