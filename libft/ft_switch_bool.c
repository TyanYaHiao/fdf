/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:49:32 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/13 15:50:13 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_switch_bool(int *value)
{
	if (*value == TRUE)
		*value = FALSE;
	else if (*value == FALSE)
		*value = TRUE;
}
