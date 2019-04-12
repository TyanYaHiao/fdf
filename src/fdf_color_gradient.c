/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_gradient.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlurker <mlurker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:32:20 by mlurker           #+#    #+#             */
/*   Updated: 2019/04/12 20:10:16 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double		percent(double start, double end, double current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			get_light(double start, double end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			color(t_field field, int start, int end)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (field.current->color == END_POINT.color)
		return (field.current->color);
	if (field.current->dx > field.current->dy)
		percentage = percent(START_POINT.x, END_POINT.x, field.current->x);
	else
		percentage = percent(START_POINT.y, END_POINT.y, field.current->y);
	red = get_light((START_POINT.color >> 16) & 0xFF,
		(END_POINT.color >> 16) & 0xFF, percentage);
	green = get_light((START_POINT.color >> 8) & 0xFF,
		(END_POINT.color >> 8) & 0xFF, percentage);
	blue = get_light(START_POINT.color & 0xFF, END_POINT.color & 0xFF,
		percentage);
	return ((red << 16) | (green << 8) | blue);
}

void		fdf_init_curr(t_field field, int start, int end)
{
	field.current->x = START_POINT.x;
	field.current->y = START_POINT.y;
	field.current->dx = ft_abs_double(END_POINT.x, START_POINT.x);
	field.current->dy = ft_abs_double(END_POINT.y, START_POINT.y);
	field.current->color = START_POINT.color;
	field.current->sx = 1;
	field.current->sy = 1;
	if (START_POINT.x > END_POINT.x)
		field.current->sx = -1;
	if (START_POINT.y > END_POINT.y)
		field.current->sy = -1;
}

int			fdf_find_color(char *str)
{
	char	*color_string;
	int		color;

	while (*str != ',' && *str != '\0')
	{
		if (*str == '-')
			str++;
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	color_string = strchr(str, ',');
	if (!color_string)
		return (DEFAULT_COLOR);
	color = ft_atoi_hex(color_string + 1);
	if (color >= 0)
		return (color);
	return (DEFAULT_COLOR);
}
