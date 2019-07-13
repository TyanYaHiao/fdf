/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:29:30 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/13 18:44:28 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*now_lst;
	t_list	*next_lst;

	if (*alst && del)
	{
		now_lst = *alst;
		while (now_lst != NULL)
		{
			next_lst = now_lst->next;
			ft_lstdelone(&now_lst, del);
			now_lst = next_lst;
		}
		*alst = NULL;
	}
}
