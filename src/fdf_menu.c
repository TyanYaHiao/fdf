/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 21:35:56 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/01 21:57:41 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_menu_init(t_menu *menu)
{
	menu->width = 400;
	menu->height = 700;
	menu->x = WINDOW_W - menu->width - 30;
	menu->y = 30;
	menu->name = "menu";
}

void		fdf_plot_menu(t_field field)
{

}