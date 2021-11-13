/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:31:23 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 19:13:59 by gcredibl         ###   ########.fr       */
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
# include "libft.h"
# include "cli.h"
# include "parser.h"
# include "exec.h"

# define APP_NAME "minishell"

# define FAIL			0
# define OK				1

void	sigint_handler(int sig);
void	restore_child_sig(void);
void	ignore_parent_sig(void);

#endif
