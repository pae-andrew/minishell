/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:39:41 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/13 17:39:41 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	lexer_quotes(t_token *token, char **p_token_end)
{
	char	*token_end;

	token_end = *p_token_end;
	token->append(token, token_end);
	if (*token_end++ == '\'')
	{
		while (*token_end && *token_end != '\'')
			token->append(token, token_end++);
	}
	else
	{
		while (*token_end && *token_end != '\"')
		{
			 if (*token_end == '\\')
				 token->append(token, token_end++);
			 token->append(token, token_end++);
		}
	}
	if (*token_end)
		token->append(token, token_end);
	*p_token_end = token_end;
}
