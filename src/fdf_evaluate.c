/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_evaluate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 20:28:21 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/27 20:32:15 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Не нашел, где функция используется */
void		fdf_isometry(double *x, double *y, double z, double angle) // функция для изменения координат из 3д в 2д, взято с форума интры кук бук, работает нормально
{
	double previous_x;
	double previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = ft_round_double((previous_x - previous_y) * cos(angle));
	*y = ft_round_double(-z + (previous_x + previous_y) * sin(angle));
}

void		fdf_evaluate(t_field *fdf)
{
	int 	i;
	double	prev_x;
	double	prev_y;
	double	prev_z;

	i = 0;
	while (i++ < fdf->width * fdf->height)
	{
		fdf->points_out[i].z *= fdf->coeff_z;
		prev_x = fdf->points_out[i].x * fdf->scale;
		prev_y = fdf->points_out[i].y * fdf->scale;
		prev_z = fdf->points_out[i].z * fdf->scale;
		fdf->points_out[i].x = ft_round_double(prev_x * (cos(fdf->angle_y) * cos(fdf->angle_z))
				- prev_y * (sin(fdf->angle_x) * sin(fdf->angle_y) * cos(fdf->angle_z) + cos(fdf->angle_x) * sin(fdf->angle_z))
				+ prev_z * (cos(fdf->angle_x) * sin(fdf->angle_y) * cos(fdf->angle_z) - sin(fdf->angle_x) * sin(fdf->angle_z)));
		fdf->points_out[i].y = ft_round_double(prev_x * (cos(fdf->angle_y) * sin(fdf->angle_z))
				+ prev_y * (cos(fdf->angle_x) * cos(fdf->angle_z) - sin(fdf->angle_x) * sin(fdf->angle_y) * sin(fdf->angle_z))
				+ prev_z * (cos(fdf->angle_x) * sin(fdf->angle_y) * sin(fdf->angle_z) + sin(fdf->angle_x) * cos(fdf->angle_z)));
		fdf->points_out[i].z = ft_round_double(- prev_x * sin(fdf->angle_y)
				- prev_y * (sin(fdf->angle_x) * cos(fdf->angle_y))
				+ prev_z * (cos(fdf->angle_x) * cos(fdf->angle_y)));
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
	double 	w_step;

	h_step = (WINDOW_H - WINDOW_BORDER) / (field->height);
	w_step = (WINDOW_W - WINDOW_BORDER) / (field->width);
	if (h_step <= w_step)
		step[0] = h_step;
	else
		step[0] = w_step;
	step[1] = (WINDOW_W - (step[0] * (field->width - 1))) / 2;
	step[2] = (WINDOW_H - (step[0] * (field->height - 1))) / 2;
}

/* Brings image to the center in MEMORY */
void		fdf_center_image(t_field *field)
{
	int 	i;
	int 	step_x;
	int 	step_y;

//	printf("height = %f\nwidth = %f\n", field->points[field->width * field->height].y - field->points[1].y,
//		   field->points[field->width * field->height].x - field->points[1].x);
	step_y = (WINDOW_H - (field->points_out[field->width * field->height].y\
			- field->points_out[1].y)) / 2 - field->points_out[1].y;
	step_x = (WINDOW_W - (field->points_out[field->width * field->height].x\
			- field->points_out[1].x)) / 2 - field->points_out[1].x;
	i = 0;
	while (i++ < field->width * field->height)
	{
		(*field).points_out[i].x += step_x + field->offset_x;
		(*field).points_out[i].y += step_y + field->offset_y;
	}
}

//void		fdf_center_image(t_field *field, int *offset_x, int *offset_y)
//{
////	printf("height = %f\nwidth = %f\n", field->points[field->width * field->height].y - field->points[1].y,
////		   field->points[field->width * field->height].x - field->points[1].x);
//	*offset_y = (WINDOW_H - (field->points[field->width * field->height].y\
//			- field->points[1].y)) / 2 - field->points[1].y;
//	*offset_x = (WINDOW_W - (field->points[field->width * field->height].x\
//			- field->points[1].x)) / 2 - field->points[1].x;
//}