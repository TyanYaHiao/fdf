/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:14:57 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/31 18:45:12 by fsmith           ###   ########.fr       */
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
	if (!(fdf_read(&fd, &num, &field, argv[1])))
		return (0);
	fdf_plot_image(&field);
//	mlx_hook(field.win_ptr, 4, 0, event, 0); // неведомая штука, с помощью которой потом будем использвать клаву и мыш (кродеться)
											// хук ивент - в терминале выводят икс и игрик координаты, на которые ты ткнул мышью в окошке
	mlx_hook(field.win_ptr, 4, 0, fdf_mouse_press, &field);
	mlx_hook(field.win_ptr, 5, 0, fdf_mouse_release, &field);
	mlx_hook(field.win_ptr, 6, 0, fdf_mouse_move, &field);
	mlx_hook(field.win_ptr, 17, 0, fdf_close, 0);
	mlx_hook(field.win_ptr, 2, 0, fdf_keyboard_press, &field);
	mlx_hook(field.win_ptr, 3, 0, fdf_keyboard_release, &field);
	mlx_loop(field.mlx_ptr); //тоже нужно
	return (0);
}
