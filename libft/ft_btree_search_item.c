/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_item.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:17:53 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 18:17:54 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*res;

	res = 0;
	if (root->left)
		res = ft_btree_search_item(root->left, data_ref, cmpf);
	if ((!(res)) && ((*cmpf)(root->item, data_ref) == 0))
		return (root->item);
	if ((!(res)) && (root->right))
		res = ft_btree_search_item(root->right, data_ref, cmpf);
	return (res);
}
