/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:04:26 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/02 17:32:19 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int				i;
	unsigned char	*us1;
	unsigned char	*us2;

	if (s1 && s2)
	{
		us1 = (unsigned char *)s1;
		us2 = (unsigned char *)s2;
		i = 0;
		while (us1[i] == us2[i] && us1[i] != '\0' && us2[i] != '\0')
			i++;
		if (us1[i] == '\0' && us2[i] == '\0')
			return (1);
		return (0);
	}
	return (0);
}
