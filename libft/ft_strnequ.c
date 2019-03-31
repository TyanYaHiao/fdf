/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:11:28 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/31 18:45:09 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	if (s1 && s2)
	{
		us1 = (unsigned char *)s1;
		us2 = (unsigned char *)s2;
		i = 0;
		while (us1[i] == us2[i] && us1[i] != '\0' && us2[i] != '\0' && i < n)
			i++;
		if ((us1[i] == '\0' && us2[i] == '\0') || i == n)
			return (1);
		return (0);
	}
	return (0);
}
