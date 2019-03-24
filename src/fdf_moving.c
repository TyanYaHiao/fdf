/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_moving.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:36:40 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/24 21:15:11 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_move_x(int keycode, t_field *fdf)
{
	t_field	temp_field;

	if (keycode == 124)
		fdf->offset_x += MOVE_STEP_X;
	else
		fdf->offset_x -= MOVE_STEP_X;
	temp_field = fdf_field_copy(*fdf);
	fdf_evaluate(&temp_field);
//	printf("move: x = %f__y = %f\n", (*fdf).points[40].x, (*fdf).points[40].y);
//	printf("movestep: x = %d__y = %d\n", fdf->offset_x, fdf->offset_y);
	fdf_plot_image(temp_field);
}

void		fdf_move_y(int keycode, t_field *fdf)
{
	t_field	temp_field;

	if (keycode == 125)
		fdf->offset_y += MOVE_STEP_Y;
	else
		fdf->offset_y -= MOVE_STEP_Y;
	temp_field = fdf_field_copy(*fdf);
	fdf_evaluate(&temp_field);
	fdf_plot_image(temp_field);
}
