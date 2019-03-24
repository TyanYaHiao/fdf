/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_evaluate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 20:28:21 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/24 21:22:56 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

	i = 0;
	while (i++ < fdf->width * fdf->height)
	{
		fdf_rotate_x_eval(&fdf->points[i].x, &fdf->points[i].y,
						  &fdf->points[i].z, fdf->angle_x);
		fdf_rotate_y_eval(&fdf->points[i].x, &fdf->points[i].y,
						  &fdf->points[i].z, fdf->angle_y);
		fdf_rotate_z_eval(&fdf->points[i].x, &fdf->points[i].y,
						  &fdf->points[i].z, fdf->angle_z);
		fdf->points[i].x += fdf->offset_x;
		fdf->points[i].y += fdf->offset_y;
	}
}

void		fdf_rotate_x_eval(double *x, double *y, double *z, double angle)
{
	double previous_y;
	double previous_z;

	previous_y = *y;
	previous_z = *z;
	*y = ft_round_double(previous_y * cos(angle) + previous_z * sin(angle));
	*z = ft_round_double(-previous_y * sin(angle) + previous_z * cos(angle));
}

void		fdf_rotate_y_eval(double *x, double *y, double *z, double angle)
{
	double previous_x;
	double previous_z;

	previous_x = *x;
	previous_z = *z;
	*x = ft_round_double(previous_x * cos(angle) + previous_z * sin(angle));
	*z = ft_round_double(-previous_x * sin(angle) + previous_z * cos(angle));
}

void		fdf_rotate_z_eval(double *x, double *y, double *z, double angle)
{
	double previous_x;
	double previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = ft_round_double(previous_x * cos(angle) - previous_y * sin(angle));
	*y = ft_round_double(previous_x * sin(angle) + previous_y * cos(angle));
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

void		fdf_center_image(t_field *field, int *offset_x, int *offset_y)
{
	int 	i;
	int 	step_x;
	int 	step_y;

//	printf("height = %f\nwidth = %f\n", field->points[field->width * field->height].y - field->points[1].y,
//		   field->points[field->width * field->height].x - field->points[1].x);
	step_y = (WINDOW_H - (field->points[field->width * field->height].y\
			- field->points[1].y)) / 2 - field->points[1].y;
	step_x = (WINDOW_W - (field->points[field->width * field->height].x\
			- field->points[1].x)) / 2 - field->points[1].x;
	i = 0;
	while (i++ < field->width * field->height)
	{
		(*field).points[i].x += step_x;
		(*field).points[i].y += step_y;
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