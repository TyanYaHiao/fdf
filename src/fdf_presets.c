/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_presets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:10:09 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/24 21:19:09 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_plot_isometry(int keycode, t_field *fdf)
{
	/* keycode not used now */
	t_field	temp_field;
	int		i;

	fdf->angle_x = 0.523599;
	temp_field = fdf_field_copy(*fdf);
	i = 0;
	printf("x = %f\ny = %f\n", (*fdf).points[34].x, (*fdf).points[34].y);
	while (i++ < fdf->width * fdf->height)
		fdf_isometry(&temp_field.points[i].x, &temp_field.points[i].y,
					 temp_field.points[i].z, 0.523599);
	printf("x = %f\ny = %f\n", (*fdf).points[34].x, (*fdf).points[34].y);
	fdf_center_image(&temp_field, &fdf->offset_x, &fdf->offset_y);
	printf("x = %f\ny = %f\n", (*fdf).points[34].x, (*fdf).points[34].y);
//	printf("x = %f\ny = %f\n", (*fdf).points[1].x, (*fdf).points[1].y);
	fdf_plot_image(temp_field);
}

void		fdf_move_to_center(t_field *fdf)
{
	t_field	temp_field;
//	fdf->offset_x = 0;
//	fdf->offset_y = 0;
//	fdf_center_image(fdf);

	temp_field = fdf_field_copy(*fdf);
	fdf_evaluate(&temp_field);
	printf("movestep: x = %d__y = %d\n", fdf->offset_x, fdf->offset_y);
	fdf_center_image(&temp_field, &fdf->offset_x, &fdf->offset_y);
	printf("movestep: x = %d__y = %d\n", fdf->offset_x, fdf->offset_y);
//	printf("iso:  x = %f__y = %f\n", (*fdf).points[40].x, (*fdf).points[40].y);
//	printf("movestep: x = %d__y = %d\n", fdf->offset_x, fdf->offset_y);
	fdf_plot_image(temp_field);
}
