/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 20:18:32 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/13 18:44:28 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_round_double(double x)
{
	double temp;

	temp = x;
	x -= (int)x;
	if (x > 0.5)
		x = (int)temp + 1;
	else
		x = (int)temp;
	return (x);
}
