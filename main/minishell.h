/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyx <sstyx@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:31:23 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/21 19:32:27 by sstyx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include "minishell.h"
# include "../libft/libft.h"
# include "../cli/cli_class/cli.h"
# include "../parser/parser.h"
# include "../exec/exec.h"

# define APP_NAME "minishell"

# define FAIL			0
# define OK				1

void	sigint_handler(int sig);
void	restore_child_sig(void);
void	ignore_parent_sig(void);

#endif
