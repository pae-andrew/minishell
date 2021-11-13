/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_p2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:38:14 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 17:38:14 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static t_env	*make_content(char *key, char *value)
{
	t_env	*result;

	result = malloc(sizeof(*result));
	if (!result)
		process_error();
	result->key = ft_strdup(key);
	if (!result->key)
		process_syserror();
	if (!value)
		result->value = 0;
	else
	{
		result->value = ft_strdup(value);
		if (!result->value)
			process_syserror();
	}
	return (result);
}

t_dlist	*find_by_key(t_dlist *lst, char *key)
{
	t_env	*content;

	while (lst)
	{
		content = lst->content;
		if (eq((content->key), key))
			return (lst);
		lst = lst->next;
	}
	return (0);
}

int	update_by_key(t_dlist *lst, char *key, char *value, t_ex_op op)
{
	t_dlist	*elem;
	t_env	*content;
	char	*tmp;

	if (!key || !value)
		return (0);
	elem = find_by_key(lst, key);
	if (elem)
	{
		content = elem->content;
		if (op == EXPORT_APPEND)
		{
			tmp = ft_strjoin(content->value, value);
			if (!tmp)
				process_syserror();
			free(content->value);
			content->value = tmp;
			return (0);
		}
		free(content->value);
		content->value = ft_strdup(value);
		if (!content->value)
			process_syserror();
	}
	return (0);
}

int	add_by_key(t_dlist **lst, char *key, char *value)
{
	t_env	*content;
	t_dlist	*elem;

	content = make_content(key, value);
	if (!content)
		return (1);
	elem = ft_dlstnew(content);
	if (!elem)
		process_syserror();
	ft_dlstadd_back(lst, elem);
	return (0);
}

int	put_env(t_dlist **lst, char *text)
{
	t_dlist	*elem;
	char	*key;
	char	*value;

	key = get_key(text);
	if (!is_valid_key(key))
	{
		free(key);
		return (1);
	}
	value = get_value(text);
	elem = find_by_key(*lst, key);
	if (elem)
		update_by_key(*lst, key, value, get_operation(text));
	else
		add_by_key(lst, key, value);
	free(key);
	free(value);
	return (0);
}
