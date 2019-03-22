/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 19:47:55 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/22 22:07:43 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_hex(char *str)
{
	int  i;
	int  num;
	char *digits;

	if (!str || str[0] != '0' || str[1] != 'x')
		return (-1);
	i = 2;
	num = 0;
	while (str[i] != '\0' && ((str[i] >= '0' && str[i] <= '9')
							  || (str[i] >= 'A' && str[i] <= 'F')))
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			num = num * 16 + str[i] - '0';
		else
			num = num * 16 + str[i] - 'A' + 10;
		i++;
	}
	return (num);
}