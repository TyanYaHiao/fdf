/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_field.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 15:20:23 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/24 19:10:12 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			fdf_field_init(t_field *initiated_field)
{
	initiated_field->height = 0;
	initiated_field->width = 0;
	initiated_field->max_depth = 0;
	initiated_field->angle_x = 0;
	initiated_field->angle_y = 0;
	initiated_field->angle_z = 0;
	initiated_field->mlx_ptr = mlx_init();
	initiated_field->win_ptr = mlx_new_window(initiated_field->mlx_ptr,
			WINDOW_W, WINDOW_H, "Fil de Fer");
//	initiated_field->img_ptr = 0; // what is it?
//	initiated_field->points = 0; // ??
}

t_field			fdf_field_copy(t_field field1)
{
	t_field		field2;
	int 		i;

	field2.points = (t_point*)malloc(sizeof(t_point) * ((field1.width + 1) * (field1.height + 1)));
	i = 0;
	while (i < (field1.width + 1) * (field1.height + 1))
	{
		field2.points[i] = field1.points[i];
		i++;
	}
	field2.angle_x = field1.angle_x;
	field2.angle_y = field1.angle_y;
	field2.angle_z = field1.angle_z;
	field2.map_name = field1.map_name;
	field2.width = field1.width;
	field2.height = field1.height;
	field2.max_depth = field1.max_depth;
	field2.img_ptr = field1.img_ptr;
	field2.win_ptr = field1.win_ptr;
	field2.mlx_ptr = field1.mlx_ptr;
	field2.x0 = field2.x0;
	field2.y0 = field2.y0;
	return (field2);
}