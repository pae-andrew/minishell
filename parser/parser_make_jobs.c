/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_make_jobs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:39:55 by gcredibl          #+#    #+#             */
/*   Updated: 2021/11/14 20:47:14 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser_append_job(t_parser *self, t_job *job)
{
	t_job	**tmp;
	size_t	i;

	i = 0;
	tmp = (t_job **)malloc(sizeof(t_job) * (self->jobs_len + 2));
	if (!tmp)
		process_syserror();
	if (self->jobs_len == 0)
	{
		tmp[0] = job;
		tmp[1] = NULL;
	}
	else
	{
		while (self->jobs[i])
		{
			tmp[i] = self->jobs[i];
			i++;
		}
		tmp[i] = job;
		tmp[++i] = NULL;
		free(self->jobs);
	}
	self->jobs = tmp;
	self->jobs_len += 1;
}

static void	parser_fill_job(t_parser *self, t_job *job, size_t *index)
{
	t_list	*redir_new;
	t_token	**tokens;
	char	*redir_file;
	size_t	i;

	i = *index;
	tokens = self->lexer->tokens;
	if ((tokens[i]->type == CMD) || (tokens[i]->type == ARG))
		job_append_arg(job, ft_strdup(tokens[i]->str));
	else if ((tokens[i]->type == REDIR_IN) || (tokens[i]->type == REDIR_OUT)
		|| (tokens[i]->type == REDIR_APPEND))
	{
		i++;
		redir_file = ft_strdup(tokens[i]->str);
		redir_new = ft_lstnew(redir_file);
		if (!redir_file || !redir_new)
			process_syserror();
		if (tokens[i - 1]->type == REDIR_IN)
			ft_lstadd_back(&(job->redir_in), redir_new);
		else if (tokens[i - 1]->type == REDIR_OUT)
			ft_lstadd_back(&(job->redir_out), redir_new);
		else if (tokens[i - 1]->type == REDIR_APPEND)
			ft_lstadd_back(&(job->redir_append), redir_new);
	}
	*index = i;
}

static void	parser_check_sep(t_parser *self, size_t *index)
{
	size_t	tokens_len;
	size_t	i;
	t_token	**tokens;

	i = *index;
	tokens_len = self->lexer->tokens_len;
	tokens = self->lexer->tokens;
	if (i < tokens_len && tokens[i]->type == SEP)
		i++;
	*index = i;
}

int	parser_make_jobs(t_parser *self)
{
	size_t	i;
	t_token	**tokens;
	t_job	*job;

	i = self->pos;
	tokens = self->lexer->tokens;
	while (i < self->lexer->tokens_len && tokens[i]->type != SEP)
	{
		job = job_new();
		if (tokens[i]->type == PIPE)
			i++;
		while (i < self->lexer->tokens_len && (tokens[i]->type != PIPE
				&& tokens[i]->type != SEP))
		{
			tokens[i]->prepare(tokens[i], self->exit_status, self->env);
			parser_fill_job(self, job, &i);
			i++;
		}
		if (job->argv)
			job->cmd = job->argv[0];
		parser_append_job(self, job);
	}
	parser_check_sep(self, &i);
	self->pos = i;
	return (0);
}
