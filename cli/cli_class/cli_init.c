/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:35:51 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/27 15:52:00 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

void	cli_update_history(t_cli *self)
{
	t_hnode		*begin;
	t_hnode		*current;

	begin = (t_hnode *)self->hist->content;
	current = (t_hnode *)self->hist_cur->content;
	if (begin == current)
		begin->hist_upd(begin, begin->buf);
	else
		begin->hist_upd(begin, current->buf);
	self->line = (t_line *)((t_hnode *)self->hist->content)->_hist;
	ft_dlstiter(self->hist, hnode_buf_upd);
}

void	cli_init(t_cli *self)
{
	self->hist = NULL;
	self->hist_cur = NULL;
	self->readline = 0;
	self->line = NULL;
}

void	cli_del(t_cli *self)
{
	ft_dlstclear(&(self->hist), hnode_del);
}

void	cli_launch_term(t_cli *self)
{
	tcgetattr(0, &(self->term));
	self->term.c_lflag &= ~(ECHO);
	self->term.c_lflag &= ~(ICANON);
	self->term.c_lflag &= ~(ISIG);
	if (tcsetattr(0, TCSANOW, &self->term) == -1)
		process_syserror();
	if (tgetent(0, "xterm-256color") == -1)
		process_syserror();
	write(1, "minishell % ", 12);
	tputs(save_cursor, 1, ft_putchar);
}

void	cli_stop_term(t_cli *self)
{
	self->term.c_lflag |= (ECHO);
	self->term.c_lflag |= (ICANON);
	self->term.c_lflag |= (ISIG);
	if (tcsetattr(0, TCSANOW, &self->term) == -1)
		process_syserror();
}
