/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_grammar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:39:31 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 17:39:31 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	lexer_check_sep(t_lexer *self, size_t i)
{
	t_token	*token_prev;

	if (i == 0)
		return (-1);
	token_prev = self->tokens[i - 1];
	if ((token_prev->type == PIPE)
		|| (token_prev->type == SEP)
		|| (token_prev->type == REDIR_IN)
		|| (token_prev->type == REDIR_OUT)
		|| (token_prev->type == REDIR_APPEND))
		return (-1);
	return (0);
}

int	lexer_check_pipe(t_lexer *self, size_t i)
{
	t_token	*token_prev;

	if ((i == 0) || (i == self->tokens_len - 1))
		return (-1);
	token_prev = self->tokens[i - 1];
	if ((token_prev->type == PIPE)
		|| (token_prev->type == SEP))
		return (-1);
	return (0);
}

int	lexer_check_redir(t_lexer *self, size_t i)
{
	t_token	*token_prev;

	if (i == self->tokens_len - 1)
		return (-1);
	if (i > 0)
	{
		token_prev = self->tokens[i - 1];
		if (token_prev->type == REDIR_IN
			|| token_prev->type == REDIR_OUT
			|| token_prev->type == REDIR_APPEND)
			return (-1);
	}
	return (0);
}

int	lexer_check_grammar(t_lexer *self)
{
	t_token	*token_cur;
	size_t	i;

	i = 0;
	while (i < self->tokens_len)
	{
		token_cur = self->tokens[i];
		if (((token_cur->type) == PIPE) && lexer_check_pipe(self, i) == -1)
			return (process_input_error(3));
		if ((token_cur->type == SEP) && lexer_check_sep(self, i) == -1)
			return (process_input_error(4));
		if (((token_cur->type == REDIR_IN)
				|| (token_cur->type == REDIR_OUT)
				|| (token_cur->type == REDIR_APPEND))
			&& (lexer_check_redir(self, i) == -1))
			return (process_input_error(5));
		i++;
	}
	return (0);
}
