/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_evaluate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 20:28:21 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/23 20:28:21 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_isometry(double *x, double *y, double z) // функция для изменения координат из 3д в 2д, взято с форума интры кук бук, работает нормально
{
	double previous_x;
	double previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = ft_round_double((previous_x - previous_y) * cos(0.523599));
	*y = ft_round_double(-z + (previous_x + previous_y) * sin(0.523599));
}

