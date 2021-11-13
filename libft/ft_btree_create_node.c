/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:17:39 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 18:17:40 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_create_node(void *item)
{
	t_btree	*res;

	res = (t_btree *)malloc(sizeof(t_btree));
	if (!res)
		return (NULL);
	res->item = item;
	res->left = NULL;
	res->right = NULL;
	return (res);
}
