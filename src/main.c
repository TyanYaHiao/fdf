/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:14:57 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/19 21:50:50 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Image faster than pixel.put */

static void iso(double *x, double *y, double z) // функция для изменения координат из 3д в 2д, взято с форума интры кук бук, работает нормально
{
	double previous_x;
	double previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

int event(int button, int x, int y, void *param)
{
	printf("%d %d\n", x, y); // это работает, потому что написала ксюша
}

int mouse_release(int button, int x, int y, void *param)
{
	button = 4;
	y *= 4;     //это штука тоже непонятно как работает, потому что я писала, я в шоке
	x *= 4;
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	// я хз что это, можешь посмотреть в кук буке для фдф (форум интры), я не разобралась
}


int				main(int argc, char **argv)
{
	int			fd;
	int 		num;
//	char 		*coordinates;
	t_field		field;

	if (!(fdf_open(argc, argv, &fd)))
		return (0);
	if (!(fdf_read(&fd, &num, &field)))
		return (0);
//	if (!(figure = (t_figure*)malloc(sizeof(*figure) * (num + 1))) || \
//		!(map_size = (int*)malloc(sizeof(*map_size) * 2)))
//		return (0);
//	if (!(fillit_validate(figure, &tetriminos, num)))
//	field_init(&field);
	int i = 0;
	while (i++ < field.width * field.height)
		connect_pxl(field, i);

	i = 0;
	while (i++ <= field.width * field.height) // прежде чем отрисовывать фигуру из 3д в 2д все ее точки нужно модифицировать
		iso(&field.points[i].x, &field.points[i].y, field.points[i].z);

	i = 0;
	while (i++ <= field.width * field.height) // дебажный вайл для получения новых, измененных координат после iso
		printf("{N(%f): X(%f) - Y(%f)}  \n", field.points[i].n, field.points[i].x, field.points[i].y);

	i = 0;
	while (i++ < field.width * field.height) // отрисовка всех точек с карты
		connect_pxl(field, i);

	mlx_hook(field.win_ptr, 4, 0, event, 0); // неведомая штука, с помощью которой потом будем использвать клаву и мыш (кродеться)
											// хук ивент - в терминале выводят икс и игрик координаты, на которые ты ткнул мышью в окошке
	mlx_hook(field.win_ptr, 6, 0, mouse_move, 0);
	mlx_loop(field.mlx_ptr); //тоже нужно
	return (0);
}
