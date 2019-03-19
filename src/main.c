/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:14:57 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/19 20:02:51 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Image faster than pixel.put */

static void iso(int *x, int *y, int z) // аффиннская херня
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * (int)0.86602529158;
	*y = -z + (previous_x + previous_y) * (int)0.50000019433;
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
//	check = 1;
//	i = 1;
//	while (i < field.width * field.height)
//	{
//		connect_pxl(field, i, check);
//		i++;
//	}

	mlx_loop(field.mlx_ptr); //тоже нужно
	return (0);
}
