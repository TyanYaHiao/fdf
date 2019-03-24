/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:14:57 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/24 16:19:24 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Image faster than pixel.put */

int				main(int argc, char **argv)
{
	int			fd;
	int 		num;
	int 		i;
//	char 		*coordinates;
	t_field		field;

	if (!(fdf_open(argc, argv, &fd)))
		return (0);
	if (!(fdf_read(&fd, &num, &field)))
		return (0);

//	/* Debug fdf isometry */
//	i = 0;
//	while (i++ < field.width * field.height)
//		printf("{N/(%f): X(%f) - Y(%f)} - Z{%f}\n", field.points[i].n,
//		field.points[i].x, field.points[i].y, field.points[i].z);

	/* Plotting image */
	fdf_plot_image(field);

//	mlx_hook(field.win_ptr, 4, 0, event, 0); // неведомая штука, с помощью которой потом будем использвать клаву и мыш (кродеться)
											// хук ивент - в терминале выводят икс и игрик координаты, на которые ты ткнул мышью в окошке
//	mlx_hook(field.win_ptr, 4, 0, mouse_press, &field);
//	mlx_hook(field.win_ptr, 17, 0, close1, 0);
	mlx_hook(field.win_ptr, 2, 0, fdf_move_key, &field);
	mlx_loop(field.mlx_ptr); //тоже нужно
	return (0);
}
