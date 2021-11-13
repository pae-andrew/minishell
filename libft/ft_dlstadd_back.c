/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:18:09 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 18:18:09 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	if (lst && new)
	{
		if (*lst)
		{
			last = ft_dlstlast(*lst);
			last->next = new;
			new->prev = last;
		}
		else
			*lst = new;
	}
}
