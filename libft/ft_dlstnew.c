/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:18:44 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 18:18:44 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*result;

	result = malloc(sizeof(t_dlist));
	if (!result)
		return (0);
	result->content = content;
	result->next = NULL;
	result->prev = NULL;
	return (result);
}
