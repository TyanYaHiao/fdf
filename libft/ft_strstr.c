/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:27:34 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/01 19:54:58 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		lenh;
	int		lenn;

	i = 0;
	lenh = ft_strlen(haystack);
	lenn = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < lenh)
	{
		if (ft_strncmp(&haystack[i], needle, lenn) != 0)
			i++;
		else
		{
			return ((char *)&haystack[i]);
		}
	}
	return (NULL);
}
