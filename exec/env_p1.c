/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_p1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:38:09 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 17:38:09 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*get_env(t_dlist *lst, char *key)
{
	t_env	*content;

	while (lst)
	{
		content = lst->content;
		if (eq((content->key), key))
			return (content->value);
		lst = lst->next;
	}
	return (0);
}

void	unset_env(t_dlist **lst, char *key)
{
	t_dlist	*elem;
	t_dlist	*head;

	if (lst && *lst)
	{
		elem = find_by_key(*lst, key);
		if (elem)
		{
			if (!elem->prev)
				head = elem->next;
			else
				head = *lst;
			free(((t_env *)elem->content)->key);
			free(((t_env *)elem->content)->value);
			ft_dlstdelone(elem, free);
			*lst = head;
		}
	}
}
