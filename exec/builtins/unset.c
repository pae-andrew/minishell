/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyx <sstyx@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:38:02 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/21 19:27:14 by sstyx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

int	exec_builtin_unset(t_exec *e)
{
	int	i;
	int	code;

	code = 0;
	i = 1;
	while (e->argv[i])
	{
		if (!is_valid_key(e->argv[i]))
			code = perr(BLTN_UNSET_NAME, e->argv[i], ERR_INVALID_ID, 1);
		else
			unset_env(&e->env, e->argv[i]);
		i++;
	}
	return (code);
}
