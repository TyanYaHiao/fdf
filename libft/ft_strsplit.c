/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:59:35 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/01 19:54:58 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_strsplit_check(char const *s, char c)
{
	char		**output;

	if (!s || !c)
		return (NULL);
	if (!(output = (char **)malloc(sizeof(char *)
			* (ft_count_words(s, c) + 1))))
		return (NULL);
	return (output);
}

static void		*ft_freetab(char ***output, size_t err_word)
{
	size_t word;

	word = 0;
	while (word < err_word)
	{
		free((*output)[word]);
		word++;
	}
	free(*output);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		pos;
	int			words;
	char		**output;

	if (!(output = ft_strsplit_check(s, c)))
		return (NULL);
	i = 0;
	pos = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c && s[i] != '\0')
			pos = ++i;
		else
			while (s[i] != c && s[i] != '\0')
			{
				if (s[i + 1] == c || s[i + 1] == '\0')
					if (!(output[words++] = ft_strsub(s, pos, (i + 1 - pos))))
						return (ft_freetab(&output, words));
				i++;
			}
	}
	output[words] = NULL;
	return (output);
}
