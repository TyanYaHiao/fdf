/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:56:28 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/13 18:44:28 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_words(char const *s, char c)
{
	int		i;
	int		count;

	if (s && c)
	{
		i = 0;
		count = 0;
		while (s[i])
		{
			if (s[i] == c && s[i] != '\0')
				i++;
			else
			{
				count++;
				while (s[i] != c && s[i] != '\0')
					i++;
			}
		}
		return (count);
	}
	return (0);
}
