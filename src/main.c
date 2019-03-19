/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:14:57 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/19 21:07:58 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Image faster than pixel.put */

static void iso(double *x, double *y, double z)
{
	double previous_x;
	double previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

//int event(int button, int x, int y, void *param)
//{
//	printf ("%d %d\n", x, y);
//}

int mouse_release(int button, int x, int y, void *param)
{
	button = 4;
	y *= 4;
	x *= 4;
	return (0);
}

int mouse_move(int x, int y, void *param)
{

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
	int i = 1;
	int check = 1;
	while (i < field.width * field.height)
	{
		connect_pxl(field, i, check);
		i++;
	}
	i = 1;
	while (i <= field.width * field.height)
	{
		iso(&field.points[i].x, &field.points[i].y, field.points[i].z);
		i++;
	}
	i = 1;
	while (i <= field.width * field.height)
	{
		printf("{N(%f): X(%f) - Y(%f)}  \n", field.points[i].n, field.points[i].x, field.points[i].y);
		i++;
	}
	i = 1;
	while (i < field.width * field.height)
	{
		connect_pxl(field, i, check);
		i++;
	}
//	check = 1;
//	i = 1;
//	while (i < field.width * field.height)
//	{
//		connect_pxl(field, i, check);
//		i++;
//	}
//	mlx_hook(field.win_ptr, 4, 0, event, 0);
	mlx_hook(field.win_ptr, 6, 0, mouse_move, 0);
	mlx_loop(field.mlx_ptr); //тоже нужно
	return (0);
}
