/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:45:32 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/01 19:54:58 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcut(char **s, char c)
{
	char	*output;
	char	*temp;
	size_t	c_pos;
	size_t	len;

	if (!ft_strchr(*s, c))
		return (NULL);
	c_pos = ft_strchr(*s, c) - *s;
	len = ft_strlen(*s) - c_pos;
	if (!(output = ft_strsub(*s, 0, c_pos)))
		return (NULL);
	temp = ft_strdup(*s);
	free(*s);
	if (len > 0)
		*s = ft_strsub(temp, (unsigned int)c_pos + 1, len);
	else
		*s = ft_strnew(0);
	free(temp);
	return (output);
}
