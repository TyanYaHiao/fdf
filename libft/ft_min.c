/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:04:12 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/01 14:31:17 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_min(int *array, int lenght)
{
	int		i;
	int		min;

	i = 0;
	min = array[i];
	while (i < lenght)
	{
		if (array[i] < min)
			min = array[i];
		i++;
	}
	return (min);
}
