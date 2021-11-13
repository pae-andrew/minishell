/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:20:03 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 18:20:03 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	void	*content;

	list = 0;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&list, del);
			break ;
		}
		ft_lstadd_back(&list, ft_lstnew(content));
		lst = lst->next;
	}
	return (list);
}
