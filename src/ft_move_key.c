
#include "../includes/fdf.h"


void 	ft_move_key(int keycode, t_field *fdf)
{
	int i = 0;

	mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
	if (keycode == 124)
	{
		while (i++ < (*fdf).width * (*fdf).height)
			(*fdf).points[i].x += 15;
		i = 0;
		while (i++ < (*fdf).width * (*fdf).height)
			connect_pxl((*fdf), i);
	}
	if (keycode == 126)
	{
		while (i++ < (*fdf).width * (*fdf).height)
			(*fdf).points[i].y -= 25;
		i = 0;
		while (i++ < (*fdf).width * (*fdf).height)
			connect_pxl((*fdf), i);
	}
	if (keycode == 125)
	{
		while (i++ < (*fdf).width * (*fdf).height)
			(*fdf).points[i].y += 15;
		i = 0;
		while (i++ < (*fdf).width * (*fdf).height)
			connect_pxl((*fdf), i);
	}
	if (keycode == 123)
	{
		while (i++ < (*fdf).width * (*fdf).height)
			(*fdf).points[i].x -= 35;
		i = 0;
		while (i++ < (*fdf).width * (*fdf).height)
			connect_pxl((*fdf), i);
	}
	if (keycode == 69)
	{
		while (i++ < (*fdf).width * (*fdf).height)
		{
			(*fdf).points[i].x *= 2;
			(*fdf).points[i].y *= 2;
		}
		i = 0;
		while (i++ < (*fdf).width * (*fdf).height)
			connect_pxl((*fdf), i);
	}
	if (keycode == 78)
	{
		while (i++ < (*fdf).width * (*fdf).height)
		{
			(*fdf).points[i].x /= 2;
			(*fdf).points[i].y /= 2;
		}
		i = 0;
		while (i++ < (*fdf).width * (*fdf).height)
			connect_pxl((*fdf), i);
	}


}

