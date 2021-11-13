/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:18:19 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 18:18:20 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstclear(t_dlist **lst, void (*del)(void*))
{
	t_dlist	*elem;

	if (lst)
	{
		while (*lst)
		{
			elem = *lst;
			*lst = (*lst)->next;
			ft_dlstdelone(elem, del);
		}
	}
}
