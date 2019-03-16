/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:14:57 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/16 21:02:22 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_abs1(int x1, int x0)
{
	int 	res;

	res = x1 - x0;
	return (res);
}

t_map	swap(t_map map)
{
	int x = (map).x1;
	int y = (map).y1;
	(map).x1 = (map).x0;
	(map).y1 = (map).y0;
	(map).x0 = x;
	(map).y0 = y;
	return(map);
}

void 	plot_line_low(t_map *map, int i, int check)
{
	if (check)
		map[i] = swap(map[i]);
	map[i].delx = ft_abs1(map[i].x1, map[i].x0);
	map[i].dely = ft_abs1(map[i].y1, map[i].y0);
	int D;
	int y;
	int yi = 1;
	if (map[i].delx < 0)
	{
		yi = -1;
		map[i].delx *= -1;
	}
	D = 2 * map[i].dely - map[i].delx;
	while (map[i].x0 < map[i].x1)
	{
		mlx_pixel_put(map[0].mlx_ptr, map[0].win_ptr, map[i].x0, map[i].y0, 0x6a5acd);
		if (D > 0)
		{
			map[i].y0 += yi;
			D -= 2 * map[i].delx;
		}
		D += 2 * map[i].dely;
		map[i].x0++;
	}
}


void 	plot_line_high(t_map *map, int i, int check)
{
	if (check)
	{
		map[i] = swap(map[i]);

	}
	map[i].delx = ft_abs1(map[i].x1, map[i].x0);
	map[i].dely = ft_abs1(map[i].y1, map[i].y0);
	int D;
	int x;
	int xi = 1;
	if (map[i].delx < 0)
	{
		xi = -1;
		map[i].delx *= -1;
	}
	D = 2 * map[i].delx - map[i].dely;
	while (map[i].y0 < map[i].y1)
	{
		mlx_pixel_put(map[0].mlx_ptr, map[0].win_ptr, map[i].x0, map[i].y0, 0x6a5acd);
		if (D > 0)
		{
			map[i].x0 += xi;
			D -= 2 * map[i].dely;
		}
		D += 2 * map[i].delx;
		map[i].y0++;
	}
}

void	plot_line(t_map *map, int i)
{

	if (map[i].dely < map[i].delx)
	{
		if (map[i].x0 > map[i].x1)
			plot_line_low(map, i, 1);
		else
			plot_line_low(map, i, 0);
	}
	else
	{
		if (map[i].y0 > map[i].y1)
			plot_line_high(map, i, 1);
		else
			plot_line_high(map, i, 0);
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

int				main()
{
	t_map	*map;
	char 	*str = "Sosatb";
	int 	k[2] = {70, 75};
	int 	j[2] = {70, 75};
	int i = 0;
	map = (t_map*)malloc(sizeof(*map) * 10);
	map[0].x0 = 90;
	map[0].x1 = 200;
	map[0].y0 = 90;
	map[0].y1 = 200;
	map[1].x1 = 90;
	map[1].x0 = 200;
	map[1].y1 = 200;
	map[1].y0 = 90;

	map[0].mlx_ptr = mlx_init(); //нужно
	map[0].win_ptr = mlx_new_window(map[0].mlx_ptr, 900, 900, "Lejatb"); //создает окно
	mlx_string_put(map[0].mlx_ptr, map[0].win_ptr, 100, 200, 0xfaebd7, str);

	mlx_pixel_put(map[0].mlx_ptr, map[0].win_ptr, map[1].x1, map[1].y1, 0xFFFFFF); //set pixel

	while (i < 2)
	{
		plot_line(map, i);
		i++;
	}


	mlx_loop(map[0].mlx_ptr); //тоже нужно
	return (0);
}
