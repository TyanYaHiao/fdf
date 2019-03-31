/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:04:12 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/31 18:45:09 by fsmith           ###   ########.fr       */
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
