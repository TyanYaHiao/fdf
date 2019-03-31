/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:56:32 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/31 18:45:09 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*us;

	us = (unsigned char *)s;
	while (n)
	{
		if (*us == (unsigned char)c)
			return (us);
		us++;
		n--;
	}
	return (NULL);
}
