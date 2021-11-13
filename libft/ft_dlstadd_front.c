/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:18:14 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 18:18:15 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	if (lst && new)
	{
		if (*lst)
		{
			(*lst)->prev = new;
			new->next = *lst;
			*lst = new;
		}
		else
			*lst = new;
	}
}
