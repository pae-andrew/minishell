/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:36:59 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 17:37:00 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

void	process_syserror(void);
void	process_error(void);
int		process_input_error(size_t errcode);
int		perr(char *cmd, char *arg, char *err, int code);

#endif
