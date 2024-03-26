/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 02:14:45 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/26 12:28:27 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_token(t_token **token, char *line, char *word, t_quote quote)
{
	while (*line)
	{
		while (*line && ft_is_white_space(*line))
			line++;
		if (!*line)
			break ;
		if (quote == NO_QUOTE)
		{
			if (*line && !ft_strncmp(line, "<<", 2))
				heredoc_token(token, &line);
			else if (*line && !ft_strncmp(line, ">>", 2))
				append_token(token, &line);
			else if (*line == '|')
				add_token(token, new_token("|", PIPE));
			else if (*line == '<')
				add_token(token, new_token("<", REDIR_IN));
			else if (*line == '>')
				add_token(token, new_token(">", REDIR_OUT));
		}
		word_token(token, &line, word, quote);
		line++;
	}
	free(word);
}

void	del_useless_quote(char **str, t_quote quote)
{
	char	*tmp;
	t_quote	tmp_quote;

	tmp = *str;
	if (!tmp)
		return ;
	while (*tmp)
	{
		tmp_quote = quote;
		quote = quote_state(tmp, quote);
		if (quote != tmp_quote)
			ft_memmove(tmp, tmp + 1, ft_strlen(tmp));
		else
			tmp++;
	}
}

void	format_tokens(t_token **token, t_env *env, t_quote quote)
{
	t_token	*tmp;

	tmp = *token;
	while (tmp)
	{
		if (tmp->type == COMMAND)
		{
			replace_vars(&(tmp->content), env, quote);
			del_useless_quote(&(tmp->content), quote);
		}
		tmp = tmp->next;
	}
}

t_token	*parse_line(char **line, t_env *env)
{
	t_token	*token;
	char	*word;

	token = NULL;
	word = NULL;
	if (check_quote(*line, NO_QUOTE))
		return (NULL);
	init_token(&token, *line, word, NO_QUOTE);
	if (check_token(token))
	{
		if (check_heredoc(token))
		{
			ft_putendl_fd("minishell: maximum here-document count exceeded", 2);
			free_token_content(token);
			free(*line);
			exit_minishell(env);
		}
		free_token_content(token);
		return (NULL);
	}
	format_tokens(&token, env, NO_QUOTE);
	free(*line);
	return (token);
}
