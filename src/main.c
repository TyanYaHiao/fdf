/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:14:57 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/13 18:44:28 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				main(int argc, char **argv)
{
	int			fd;
	t_field		field;

	if (!(fdf_open(argc, argv, &fd)))
		return (0);
	if (!(fdf_read(&fd, &field, argv[1])))
		return (0);
	fdf_plot_image(&field);
	mlx_hook(field.win_ptr, 4, 0, fdf_mouse_press, &field);
	mlx_hook(field.win_ptr, 5, 0, fdf_mouse_release, &field);
	mlx_hook(field.win_ptr, 6, 0, fdf_mouse_move, &field);
	mlx_hook(field.win_ptr, 17, 0, fdf_close, 0);
	mlx_hook(field.win_ptr, 2, 0, fdf_keyboard_press, &field);
	mlx_hook(field.win_ptr, 3, 0, fdf_keyboard_release, &field);
	mlx_loop(field.mlx_ptr);
	return (0);
}
