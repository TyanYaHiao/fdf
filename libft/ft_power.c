/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:31:08 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/01 19:54:58 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_power(int num, int power_level)
{
	size_t	result;

	if (power_level < 0)
		return (0);
	result = 1;
	while (power_level > 0)
	{
		result *= num;
		power_level--;
	}
	return (result);
}
