/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:07:27 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/01 11:03:05 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		match;

	match = 0;
	while (*s)
	{
		if (*s == c)
		{
			tmp = ((char*)s);
			match = 1;
		}
		s++;
	}
	if (match == 1)
		return (tmp);
	if (*s == c && c == '\0')
		return ((char*)s);
	else
		return (NULL);
}
