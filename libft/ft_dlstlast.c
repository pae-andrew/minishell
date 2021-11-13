/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:18:39 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 18:18:40 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	t_dlist	*result;

	result = 0;
	while (lst)
	{
		result = lst;
		lst = lst->next;
	}
	return (result);
}
