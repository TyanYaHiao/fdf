/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rainbow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <mlurker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:33:52 by mlurker           #+#    #+#             */
/*   Updated: 2019/04/01 18:11:48 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "../includes/fdf.h"

double		percent1(double start, double end, double current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			get_light1(double start, double end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			get_color1(t_field field, int start_index, int end_index)
{
	int     red;
	int     green;
	int     blue;
	double  percentage;
	double  dx = ft_abs_double(END_POINT.x, START_POINT.x);
	double  dy = ft_abs_double(END_POINT.y, START_POINT.y);

	if (field.points_out->color == END_POINT.color)
		return (field.points_out->color);
	if (dx > dy)
		percentage = percent1(START_POINT.x, END_POINT.x, field.points_out->x);
	else
		percentage = percent1(START_POINT.y, END_POINT.y, field.points_out->y);
	red = get_light1((START_POINT.color >> 16) & 0xFF, (END_POINT.color >> 16) & 0xFF, percentage);
	green = get_light1((START_POINT.color >> 8) & 0xFF, (END_POINT.color >> 8) & 0xFF, percentage);
	blue = get_light1(START_POINT.color & 0xFF, END_POINT.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}


void		fdf_rainbow(t_field *fdf, int keycode)
{
	time_t		current_time;
	struct tm	timer = {0};
	int 		color = 0xC0819F;
	double		seconds;

	seconds = time(&current_time);

	while(keycode != KEY_K || time(&current_time) < seconds + 60)
	{
		while (time(&current_time) < seconds + 2)
		{
			int i = 1;
			fdf->points_out[i].color = color;
			i++;
			while (++i < fdf->width * fdf->height)
				fdf->points_out[i].color = get_color(*fdf, i - 1, i);
			fdf_points_copy(fdf);
			fdf_evaluate(fdf);
			fdf_center_image(fdf);
			fdf_plot_image(fdf);
		}
	}
}