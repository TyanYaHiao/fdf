/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:14:57 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/11 16:58:49 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_abs1(int x1, int x0)
{
	int 	res;

	res = x1 - x0;
	if (res >= 0)
		return (res);
	return (res * (-1));
}

void	print_vertical(t_map map)
{
	int 	delx = ft_abs1(map.x1, map.x0);
	int 	dely = ft_abs1(map.y1, map.y0);
	int i = 0;

	while (i <= 2 * dely)
	{
		if (map.y0 <= map.y1)
		{
			mlx_pixel_put(map.mlx_ptr, map.win_ptr, map.x0, map.y0, 0xFFFFFF);
			i++;
			map.y0++;
		}
		else if (map.y0 >= map.y1)
		{
			mlx_pixel_put(map.mlx_ptr, map.win_ptr, map.x1, map.y1, 0xFFFFFF);
			i++;
			map.y1--;
		}
	}
}

void	print_horisontal(t_map map)
{
	int 	delx = ft_abs1(map.x1, map.x0);
	int i = 0;

	mlx_pixel_put(map.mlx_ptr, map.win_ptr, map.x1, map.y1, 0xFFFFFF);
	while (i <= delx * 2)
	{
		if (map.x0 <= map.x1)
		{
			mlx_pixel_put(map.mlx_ptr, map.win_ptr, map.x0, map.y0, 0xFFFFFF);
			i++;
			map.x0++;
		}
		else
		{
			mlx_pixel_put(map.mlx_ptr, map.win_ptr, map.x1, map.y1, 0xFFFFFF);
			i++;
			map.x1--;
		}
	}
}

void 	print_low(t_map map)
{
	int i = 1;
	int Dxy = 2 *(map.delx - map.dely);
	int y = map.y0;

//	while (i <= map.delx && )
	{
		if (map.x0 < map.x1)
		{
			mlx_pixel_put(map.mlx_ptr, map.win_ptr, map.x0, map.y0, 0xFFFFFF);

		}

	}
}

void 	plot_line_low(t_map map)
{
	int i = 0;
	int 	x = map.x1;

	while (i < map.delx)
	{
		if (map.x0 < map.x1)
		{
			mlx_pixel_put(map.mlx_ptr, map.win_ptr, map.x0, map.y0, 0xFFFFFF);
			map.x0++;
		}
		else
		{
			mlx_pixel_put(map.mlx_ptr, map.win_ptr, x, map.y1, 0xFFFFFF);
			x--;
		}
		i++;
	}
}

int				main()
{
	t_map	*map;
	char 	*str = "Window";
	int 	k[2] = {70, 75};
	int 	j[2] = {70, 75};
	int i = -1;
	map = (t_map*)malloc(sizeof(*map) * 10);
	map[0].x0 = 90;
	map[0].x1 = 200;
	map[0].y0 = 90;
	map[0].y1 = 200;
	map[1].x1 = 90;
	map[1].x0 = 200;
	map[1].y1 = 90;
	map[1].y0 = 200;


	map[0].mlx_ptr = mlx_init();
	map[0].win_ptr = mlx_new_window(map[0].mlx_ptr, 500, 500, "mlx 42");
	map[0].img_ptr = mlx_new_image(map[0].mlx_ptr, 100, 100);
	mlx_put_image_to_window(map[0].mlx_ptr, map[0].win_ptr, map[0].img_ptr, 100, 100);
	mlx_xpm_file_to_image(map[0].mlx_ptr, "0 0 0 0 1 1 1 2 2 2 2", k, j);
	mlx_string_put(map[0].mlx_ptr, map[0].win_ptr, 100, 100, 0xfaebd7, str);


	double 	err = 0;
//	int 	delerr = dely / delx;
	int 	diry = 1;

	mlx_pixel_put(map[0].mlx_ptr, map[0].win_ptr, map[0].x1, map[0].y1, 0xFFFFFF);
//	print_low(map);
//	print_horisontal(map);
//	print_vertical(map);

	map[0].delx = ft_abs1(map[0].x1, map[0].x0);
	map[0].dely = ft_abs1(map[0].y1, map[0].y0);

	while (i++ < 2)
		plot_line_low(map[0]);
//	else
//		plot_line_high();

	mlx_loop(map[0].mlx_ptr);
	return (0);
}
