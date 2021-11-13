/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:38:43 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 17:38:44 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	create_pipe_redir_fd1(t_exec *e, int i)
{
	pipe(e->pipe);
	if (e->count - i > 1)
		dup2(e->pipe[1], STDOUT_FILENO);
	else
		dup2(e->fd1, STDOUT_FILENO);
}

void	redir_fd0_close_pipe(t_exec *e)
{
	dup2(e->pipe[0], STDIN_FILENO);
	close(e->pipe[0]);
	close(e->pipe[1]);
}

void	close_child_fds(t_exec *e)
{
	close(e->pipe[0]);
	close(e->pipe[1]);
	close(e->fd0);
	close(e->fd1);
}

void	save_fds(t_exec *e)
{
	e->fd0 = dup(STDIN_FILENO);
	e->fd1 = dup(STDOUT_FILENO);
}

void	restore_fds(t_exec *e)
{
	dup2(e->fd0, STDIN_FILENO);
	dup2(e->fd1, STDOUT_FILENO);
	close(e->fd0);
	close(e->fd1);
}
