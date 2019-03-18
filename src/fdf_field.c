/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_field.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 15:20:23 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/17 21:52:47 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			field_init(t_field *initiated_field)
{
	initiated_field->height = 0;
	initiated_field->width = 0;
	initiated_field->max_depth = 0;
//	initiated_field->mlx_ptr = mlx_init();
//	initiated_field->win_ptr = mlx_new_window(initiated_field->mlx_ptr,
//			900, 900, "Fil de Fer");
//	initiated_field->img_ptr = 0; // what is it?
//	initiated_field->points = 0; // ??
}
