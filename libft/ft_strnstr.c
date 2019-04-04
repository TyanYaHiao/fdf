/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:58:22 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/02 15:26:56 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		lenh;
	size_t		lenn;

	i = 0;
	lenh = ft_strlen(haystack);
	lenn = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < lenh && i + lenn <= len)
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
