/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:12:45 by pcollio-          #+#    #+#             */
/*   Updated: 2019/10/15 18:31:41 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			fdf_show_help2(t_field field)
{
	mlx_string_put(field.mlx_ptr, field.win_ptr, HELP_X, HELP_Y + 180,
		TEXT_COLOR, "Move to center: <SPACE>");
	mlx_string_put(field.mlx_ptr, field.win_ptr, HELP_X, HELP_Y + 200,
		TEXT_COLOR, "Isometric view: <I>");
	mlx_string_put(field.mlx_ptr, field.win_ptr, HELP_X, HELP_Y + 220,
		TEXT_COLOR, "Top view: <T>");
}

void			fdf_show_help(t_field field)
{
	mlx_string_put(field.mlx_ptr, field.win_ptr,
		10, WINDOW_H - 30, TEXT_COLOR, "Press <H> for help");
	if (field.control->help == TRUE)
	{
		mlx_string_put(field.mlx_ptr, field.win_ptr, HELP_X, HELP_Y,
			TEXT_COLOR, "Move: keyboard arrows or");
		mlx_string_put(field.mlx_ptr, field.win_ptr, HELP_X + 62, HELP_Y + 20,
			TEXT_COLOR, "mouse move + mid button + control");
		mlx_string_put(field.mlx_ptr, field.win_ptr, HELP_X, HELP_Y + 40,
			TEXT_COLOR, "Rotation: numpad or");
		mlx_string_put(field.mlx_ptr, field.win_ptr, HELP_X + 62, HELP_Y + 60,
			TEXT_COLOR, "mouse move + mid button");
		mlx_string_put(field.mlx_ptr, field.win_ptr, HELP_X, HELP_Y + 80,
			TEXT_COLOR, "Zoom: <+> & <-> or");
		mlx_string_put(field.mlx_ptr, field.win_ptr, HELP_X + 62, HELP_Y + 100,
			TEXT_COLOR, "mouse scroll");
		mlx_string_put(field.mlx_ptr, field.win_ptr, HELP_X, HELP_Y + 120,
			TEXT_COLOR, "Change height: <Z> & <X>");
		mlx_string_put(field.mlx_ptr, field.win_ptr, HELP_X, HELP_Y + 140,
			TEXT_COLOR, "Change colors: <Q> & <W>");
		mlx_string_put(field.mlx_ptr, field.win_ptr, HELP_X, HELP_Y + 160,
			TEXT_COLOR, "More colors: <E>");
		fdf_show_help2(field);
	}
}

void			fdf_field_info2(t_field field)
{
	char	*txt;

	mlx_string_put(field.mlx_ptr, field.win_ptr,
			WINDOW_W - 150, 50, TEXT_COLOR, "Scale:");
	txt = ft_itoa(field.scale * 100);
	mlx_string_put(field.mlx_ptr, field.win_ptr,
				WINDOW_W - 60, 50, TEXT_COLOR, txt);
	free(txt);
	mlx_string_put(field.mlx_ptr, field.win_ptr,
				WINDOW_W - 150, 70, TEXT_COLOR, "Deepness:");
	txt = ft_itoa(-field.coeff_z);
	mlx_string_put(field.mlx_ptr, field.win_ptr,
			WINDOW_W - 60, 70, TEXT_COLOR, txt);
	free(txt);
	mlx_string_put(field.mlx_ptr, field.win_ptr,
			WINDOW_W - 150, 90, TEXT_COLOR, "X angle:");
	txt = ft_itoa(field.angle_x * 180 / M_PI);
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 60, 90,
			TEXT_COLOR, txt);
	free(txt);
}

void			fdf_field_info3(t_field field)
{
	char	*txt;

	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 150, 110,
				TEXT_COLOR, "Y angle:");
	txt = ft_itoa(field.angle_y * 180 / M_PI);
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 60, 110,
				TEXT_COLOR, txt);
	free(txt);
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 150, 130,
			TEXT_COLOR, "Z angle:");
	txt = ft_itoa(field.angle_z * 180 / M_PI);
	mlx_string_put(field.mlx_ptr, field.win_ptr, WINDOW_W - 60, 130,
				TEXT_COLOR, txt);
	free(txt);
}

void			fdf_field_info(t_field field)
{
	char	*txt;

	mlx_string_put(field.mlx_ptr, field.win_ptr, 10, 10,
		TEXT_COLOR, field.map_name);
	mlx_string_put(field.mlx_ptr, field.win_ptr,
		WINDOW_W - 150, 10, TEXT_COLOR, "Offset x:");
	txt = ft_itoa(field.offset_x);
	mlx_string_put(field.mlx_ptr, field.win_ptr,
		WINDOW_W - 60, 10, TEXT_COLOR, txt);
	free(txt);
	mlx_string_put(field.mlx_ptr, field.win_ptr,
		WINDOW_W - 150, 30, TEXT_COLOR, "Offset y:");
	txt = ft_itoa(field.offset_y);
	mlx_string_put(field.mlx_ptr, field.win_ptr,
		WINDOW_W - 60, 30, TEXT_COLOR, txt);
	free(txt);
	fdf_field_info2(field);
	fdf_field_info3(field);
	fdf_show_help(field);
}
