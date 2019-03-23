/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_field.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 15:20:23 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/23 17:03:31 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			fdf_field_init(t_field *initiated_field)
{
	initiated_field->height = 0;
	initiated_field->width = 0;
	initiated_field->max_depth = 0;
	initiated_field->mlx_ptr = mlx_init();
	initiated_field->win_ptr = mlx_new_window(initiated_field->mlx_ptr,
			WINDOW_W, WINDOW_H, "Fil de Fer");
//	initiated_field->img_ptr = 0; // what is it?
//	initiated_field->points = 0; // ??
}
