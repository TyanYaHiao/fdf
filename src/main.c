/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:14:57 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/21 17:51:14 by mlurker          ###   ########.fr       */
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

int close1(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int event(int button, int x, int y, void *param)
{
	printf("%d %d\n", x, y); // это работает, потому что написала ксюша
}

int mouse_release(int button, int x, int y, void *param)
{
	if (button == 4)
	{
		y *= 4;     //это штука тоже непонятно как работает, потому что я писала, я в шоке
		x *= 4;
	}
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	// я хз что это, можешь посмотреть в кук буке для фдф (форум интры), я не разобралась
}

void		ft_okrogli_x(double *x) // функция для округления дабл в большую сторону, т к приведение к инту всегда округляет так 0.9 = 0
{
	double x1 = *x;
	*x -= (int)*x;
	if (*x > 0.5)
		*x = (int)x1 + 1;
	else
		*x = (int)x1;
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
//	while (i++ < field.width * field.height)
//		connect_pxl(field, i);

	i = 0;
	while (i++ < field.width * field.height) // прежде чем отрисовывать фигуру из 3д в 2д все ее точки нужно модифицировать
	{
		iso(&field.points[i].x, &field.points[i].y, field.points[i].z);
		ft_okrogli_x(&field.points[i].x);
		ft_okrogli_x(&field.points[i].y);
	}

	i = 0;
	while (i++ < field.width * field.height) // дебажный вайл для получения новых, измененных координат после iso
	{
		printf("{X(%d)",(int) field.points[i].x);
		printf(" -  Y(%f)\n", field.points[i].y);
	}

	i = 0;
//	while (i++ < field.width * field.height) // дебажный вайл для получения новых, измененных координат после iso
//		printf("{N/(%f): X(%f) - Y(%f)} - Z{%f}\n", field.points[i].n, field.points[i].x, field.points[i].y, field.points[i].z);

	while (i++ < field.width * field.height) // отрисовка всех точек с карты
		connect_pxl(field, i);

//	mlx_hook(field.win_ptr, 4, 0, event, 0); // неведомая штука, с помощью которой потом будем использвать клаву и мыш (кродеться)
											// хук ивент - в терминале выводят икс и игрик координаты, на которые ты ткнул мышью в окошке
//	mlx_hook(field.win_ptr, 6, 0, mouse_release(4, 0, 0, 0), 0);
//	mlx_hook(field.win_ptr, 17, 0, close1, 0);
	mlx_loop(field.mlx_ptr); //тоже нужно
	return (0);
}
