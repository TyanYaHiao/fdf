/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_presets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:10:09 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/25 20:07:28 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_plot_isometry(int keycode, t_field *fdf)
{
	/* keycode not used now */
	int		i;

	fdf->angle_x = 0.523599;
	fdf_points_copy(fdf);
	i = 0;
	printf("x = %f\ny = %f\n", (*fdf).points_mem[34].x, (*fdf).points_mem[34].y);
	while (i++ < fdf->width * fdf->height)
		fdf_isometry(&fdf->points_out[i].x, &fdf->points_out[i].y,
					 fdf->points_out[i].z, 0.523599);
	printf("x = %f\ny = %f\n", (*fdf).points_mem[34].x, (*fdf).points_mem[34].y);
	fdf_center_image(fdf);
	printf("x = %f\ny = %f\n", (*fdf).points_mem[34].x, (*fdf).points_mem[34].y);
//	printf("x = %f\ny = %f\n", (*fdf).points[1].x, (*fdf).points[1].y);
	fdf_plot_image(*fdf);
}

void		fdf_plot_top_view(int keycode, t_field *fdf)
{
	/* keycode not used now */
	int		i;

	fdf->angle_x = 0;
	fdf->angle_y = 0;
	fdf->angle_z = 0;
	fdf->offset_x = 0;
	fdf->offset_y = 0;
	fdf_points_copy(fdf);
	fdf_center_image(fdf);
	fdf_plot_image(*fdf);
}

void		fdf_move_to_center(t_field *fdf)
{
//	fdf->offset_x = 0;
//	fdf->offset_y = 0;
//	fdf_center_image(fdf);

	fdf->offset_x = 0;
	fdf->offset_y = 0;
	fdf_points_copy(fdf);
	fdf_evaluate(fdf);
//	printf("movestep: x = %d__y = %d\n", fdf->offset_x, fdf->offset_y);
	fdf_center_image(fdf);
//	printf("movestep: x = %d__y = %d\n", fdf->offset_x, fdf->offset_y);
//	printf("iso:  x = %f__y = %f\n", (*fdf).points[40].x, (*fdf).points[40].y);
//	printf("movestep: x = %d__y = %d\n", fdf->offset_x, fdf->offset_y);
	fdf_plot_image(*fdf);
}
