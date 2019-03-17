/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:14:57 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/17 19:00:26 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Image faster than pixel.put */
int		ft_abs1(int x1, int x0)
{
	int 	res;

	res = x1 - x0;
	return (res);
}

void 	plot_line_low(t_map *map, int i, int j)
{
	int delx = ft_abs1(map[j].x0, map[i].x0);
	int dely = ft_abs1(map[j].y0, map[i].y0);
	int D;
	int y;
	int yi = 1;
	if (dely < 0)
	{
		yi = -1;
		dely *= -1;
	}
	D = 2 * dely - delx;
	while (map[i].x0 <= map[j].x0)
	{
//		mlx_string_put(map[0].mlx_ptr, map[0].win_ptr, 500, 200, 0xafeeee, "check");
		mlx_pixel_put(map[0].mlx_ptr, map[0].win_ptr, map[i].x0, map[i].y0, 0xafeeee);
		if (D > 0)
		{
			map[i].y0 += yi;
			D -= 2 * delx;
		}
		D += 2 * dely;
		map[i].x0++;
	}
}


void 	plot_line_high(t_map *map, int i, int j)
{
	int delx = ft_abs1(map[j].x0, map[i].x0);
	int dely = ft_abs1(map[j].y0, map[i].y0);
	int D;
	int xi = 1;
	if (delx < 0)
	{
		xi = -1;
		delx *= -1;
	}
	D = 2 * delx - dely;
	while (map[i].y0 <= map[j].y0)
	{
		mlx_string_put(map[0].mlx_ptr, map[0].win_ptr, 600, 200, 0x6b8e23, "check1");
		mlx_pixel_put(map[0].mlx_ptr, map[0].win_ptr, map[i].x0, map[i].y0, 0x6b8e23);
		if (D > 0)
		{
			map[i].x0 += xi;
			D -= 2 * dely;
		}
		D += 2 * delx;
		map[i].y0++;
	}
}

void	plot_line(t_map *map, int i) // модифицированный алгоритм отрисовки линий
{
	int delx = ft_abs1(map[i + 1].x0, map[i].x0);
	int dely = ft_abs1(map[i + 1].y0, map[i].y0);
	if (dely < delx)
	{
		if (map[i].x0 > map[i + 1].x0)
			plot_line_low(map, i + 1, i);
		else
			plot_line_low(map, i, i + 1);
	}
	else
	{
		if (map[i].y0 > map[i + 1].y0)
			plot_line_high(map, i + 1, i);
		else
			plot_line_high(map, i, i + 1);
	}
}

//void	plot_line(t_map *map, int i)
//{
//	map[i].delx = ft_abs1(map[i].x1, map[i].x0);
//	map[i].dely = ft_abs1(map[i].y1, map[i].y0);
//	double 	err = 0;
//	int 	delerr = map[i].dely / map[i].delx;
//	int 	diry = 1;
//	if (map[i].dely < 0)
//		diry = -1;
//
//	while (map[i].x0 < map[i].x1)
//	{
//		mlx_string_put(map.mlx_ptr, map.win_ptr, 100, 200, 0xfaebd7, "Xyu");
//		mlx_pixel_put(map[0].mlx_ptr, map[0].win_ptr, map[i].x0, map[i].y0, 0x6a5acd);
//		err += delerr;
//		if (err >= 0.5)
//		{
//			map[i].y0 += diry;
//			err -= 1;
//		}
//		map[i].x0++;
//	}
//}

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
	mlx_loop(field.mlx_ptr); //тоже нужно
	return (0);



//	char buff[200];
//	int fd = open("/Users/mlurker/Desktop/fdf/test/basictest.fdf", O_RDONLY);
//	ssize_t r = read(fd, &buff, 200);
//	char *point;
//	point = ft_strdup(buff);
////	ft_strcpy(point, buff);
//	t_map *map;
//	char *str = "Sosatb";
//	int k[2] = {70, 75};
//	int j[2] = {70, 75};
//	int i = 0;
//	map = (t_map *) malloc(sizeof(*map) * 10);
////	map[1].x0 = 400;
////	map[1].y0 = 200;
////	map[0].x0 = 300;
////	map[0].y0 = 350;

//	map[0].mlx_ptr = mlx_init(); //нужно
//	map[0].win_ptr = mlx_new_window(map[0].mlx_ptr, 900, 900, "Lejatb"); //создает окно
//	mlx_string_put(map[0].mlx_ptr, map[0].win_ptr, 100, 200, 0xfaebd7, str);
//
//	mlx_pixel_put(map[0].mlx_ptr, map[0].win_ptr, map[1].x1, map[1].y1, 0xFFFFFF); //set pixel
//
////	while (i < 2)
////	{
////		plot_line(map, 1);
////		i++;
////	}
//
//	i = 0;
//	int x = 100;
//	int y = 100;
//	while (*point != '\0')
//	{
//		while (*point != '\n')		// тут я пытаюсь записватьь координаты
//		{
//			if (*point != ' ')
//			{
//				map[i].x0 = x;
//				map[i].y0 = y;
//				map[i].z = *point;
//				point++;
//				x += 50;
//				mlx_pixel_put(map[0].mlx_ptr, map[0].win_ptr, map[i].x0, map[i].y0, 0x5f9ea0);
//			}
//			point++;;
//		}
//		y += 50;
//		x = 100;
//		i++;
//		point++;
//	}
////	i = 0;
////	while (i < 4)
////	{
////		iso(&map[i].x0, &map[i].y0, map[i].z);
////		i++;
////	}
//	i = 0;
//	while (i < 2)
//	{
////		mlx_string_put(map[0].mlx_ptr, map[0].win_ptr, 600, 200- 10 * i, 0x6b8e23, "check_");
//		plot_line(map, i);
//		i++;
//	}
//	mlx_loop(map[0].mlx_ptr); //тоже нужно
//	return (0);
}
