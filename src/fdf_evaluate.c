/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_evaluate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 20:28:21 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/12 18:18:24 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_rotate_x_eval(double *y, double *z, double angle)
{
	double previous_y;
	double previous_z;

	previous_y = *y;
	previous_z = *z;
	*y = ft_round_double(previous_y * cos(angle) + previous_z * sin(angle));
	*z = ft_round_double(-previous_y * sin(angle) + previous_z * cos(angle));
}

void		fdf_rotate_y_eval(double *x, double *z, double angle)
{
	double previous_x;
	double previous_z;

	previous_x = *x;
	previous_z = *z;
	*x = ft_round_double(previous_x * cos(angle) + previous_z * sin(angle));
	*z = ft_round_double(-previous_x * sin(angle) + previous_z * cos(angle));
}

void		fdf_rotate_z_eval(double *x, double *y, double angle)
{
	double previous_x;
	double previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = ft_round_double(previous_x * cos(angle) - previous_y * sin(angle));
	*y = ft_round_double(previous_x * sin(angle) + previous_y * cos(angle));
}

void		fdf_evaluate(t_field *fdf)
{
	int		i;

	i = 0;
	while (i++ < fdf->width * fdf->height)
	{
		fdf->points_out[i].z *= fdf->coeff_z;
		fdf->points_out[i].x *= fdf->scale;
		fdf->points_out[i].y *= fdf->scale;
		fdf->points_out[i].z *= fdf->scale;
		fdf_rotate_x_eval(&fdf->points_out[i].y,
				&fdf->points_out[i].z, fdf->angle_x);
		fdf_rotate_y_eval(&fdf->points_out[i].x,
				&fdf->points_out[i].z, fdf->angle_y);
		fdf_rotate_z_eval(&fdf->points_out[i].x, &fdf->points_out[i].y,
				fdf->angle_z);
		fdf->points_out[i].x += fdf->offset_x;
		fdf->points_out[i].y += fdf->offset_y;
	}
}

/*
** step[0] - step
** step[1] - X start_pos
** step[2] - Y start_pos
** step[3] - reserved for Z
*/

void		fdf_start_values(double *step, t_field *field)
{
	double	h_step;
	double	w_step;

	h_step = (WINDOW_H - WINDOW_BORDER) / (field->height);
	w_step = (WINDOW_W - WINDOW_BORDER) / (field->width);
	if (h_step <= w_step)
		step[0] = h_step;
	else
		step[0] = w_step;
	step[1] = (WINDOW_W - (step[0] * (field->width - 1))) / 2;
	step[2] = (WINDOW_H - (step[0] * (field->height - 1))) / 2;
}
