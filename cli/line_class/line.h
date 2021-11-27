/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:36:43 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/27 16:17:00 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include <stdlib.h>
# include "../../libft/libft.h"
# include "../../errors/errors.h"

typedef struct s_line
{
	char	*str;
	int		len;
	void	(*append)(struct s_line *self, char *to_append, int size);
	char	(*pop_last)(struct s_line	*self);
	void	(*del)(void *self);
}				t_line;

t_line	*line_new(void);
void	line_del(void *self);
char	line_pop_last(t_line *self);
void	line_append(t_line *self, char *src, int nbytes);
t_line	*line_dup(t_line *line);

#endif
