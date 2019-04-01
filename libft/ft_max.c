/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:00:11 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/01 15:34:55 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_max(int *array, int lenght)
{
	int		i;
	int		max;

	i = 0;
	max = array[i];
	while (i < lenght)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}
