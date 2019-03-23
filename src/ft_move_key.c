
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
			fdf_plot_image((*fdf), i);
	}
	if (keycode == 126)
	{
		while (i++ < (*fdf).width * (*fdf).height)
			(*fdf).points[i].y -= 25;
		i = 0;
		while (i++ < (*fdf).width * (*fdf).height)
			fdf_plot_image((*fdf), i);
	}
	if (keycode == 125)
	{
		while (i++ < (*fdf).width * (*fdf).height)
			(*fdf).points[i].y += 15;
		i = 0;
		while (i++ < (*fdf).width * (*fdf).height)
			fdf_plot_image((*fdf), i);
	}
	if (keycode == 123)
	{
		while (i++ < (*fdf).width * (*fdf).height)
			(*fdf).points[i].x -= 35;
		i = 0;
		while (i++ < (*fdf).width * (*fdf).height)
			fdf_plot_image((*fdf), i);
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
			fdf_plot_image((*fdf), i);
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
			fdf_plot_image((*fdf), i);
	}
}

int key_press(int keycode, t_field *fdf)
{
	if (keycode == 124 || keycode == 125 || keycode == 123 || keycode == 126 || keycode == 69 || keycode == 78)
		ft_move_key(keycode, fdf);
}

int mouse_press(int button, int x, int y, t_field *fdf)
{
	int i = 0;
	mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
	if (button == 1)
	{
		while (i++ < (*fdf).width * (*fdf).height)
			(*fdf).points[i].x *= 2;
		i = 0;
		while (i++ < (*fdf).width * (*fdf).height)
			fdf_plot_image((*fdf), i);
	}
	if (button == 2)
	{
		while (i++ < (*fdf).width * (*fdf).height)
			(*fdf).points[i].x /= 2;
		i = 0;
		while (i++ < (*fdf).width * (*fdf).height)
			fdf_plot_image((*fdf), i);
	}
//	printf("%d %d\n", x, y);
	// я хз что это, можешь посмотреть в кук буке для фдф (форум интры), я не разобралась
	return (0);
}

int event(int button, int x, int y, void *param)
{
	printf("%d %d\n", x, y); // это работает, потому что написала ксюша
	return (0);
}

int mouse_release(int button, int x, int y, void *param)
{

	{
		printf("%d %d\n", x, y);
		y *= 4;     //это штука тоже непонятно как работает, потому что я писала, я в шоке
		x *= 4;
	}
//	return (0);
}
