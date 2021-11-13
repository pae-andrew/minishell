/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:37:39 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 17:37:40 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_builtin_env(t_exec *e)
{
	t_dlist	*lst;
	t_env	*content;
	int		code;

	code = 0;
	lst = e->env;
	while (lst)
	{
		content = lst->content;
		if (content->value)
			if (printf("%s=%s\n", content->key, content->value) == -1)
				code = 1;
		lst = lst->next;
	}
	return (code);
}
