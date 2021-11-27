/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyx <sstyx@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:38:24 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/21 19:27:32 by sstyx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef enum e_ex_op {
	EXPORT_NOOP,
	EXPORT_UPDATE,
	EXPORT_APPEND
}			t_ex_op;

typedef struct s_env {
	char	*key;
	char	*value;
}			t_env;

char	*get_env(t_dlist *lst, char *key);
int		put_env(t_dlist **lst, char *text);
void	unset_env(t_dlist **lst, char *key);
t_dlist	*find_by_key(t_dlist *lst, char *key);
int		update_by_key(t_dlist *lst, char *key, char *value, t_ex_op op);

#endif
