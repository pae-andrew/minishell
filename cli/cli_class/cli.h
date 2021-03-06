/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:36:09 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/27 16:59:49 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H

# include <term.h>
# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>

# include "../../libft/libft.h"
# include "../../errors/errors.h"
# include "../line_class/line.h"
# include "../hist_node_class/hist_node.h"

typedef struct s_cli
{
	t_dlist			*hist;
	t_dlist			*hist_cur;
	struct termios	term;
	t_line			*line;
	int				readline;
}				t_cli;

int		cli_readline(t_cli *self);
void	cli_init(t_cli *self);
void	cli_del(t_cli *self);
void	cli_launch_term(t_cli *self);
void	cli_stop_term(t_cli *self);
void	cli_update_history(t_cli *self);

#endif
