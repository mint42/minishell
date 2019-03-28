/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:10:06 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/27 19:43:14 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "expand.h"
#include "libft.h"

static void		get_line_until_quote(char **input, char c)
{
	char	*line;
	size_t	len;

	line = 0;
	*input = ft_strcata(input, "\n\0");
	while (42)
	{
		ft_printf("> ");
		if ((get_next_line(1, &line)) != 1)
			continue;
		len = (line) ? ft_strlen(line) : 1;
		if (ft_strchr(line, c))
		{
			*input = ft_strncata(input, line, len);
			break ;
		}
		else
		{
			line[len - 1] = '\n';
			*input = ft_strncata(input, line, len);
		}
	}
}

void			expand_single_quotes(char **squote, char **input, size_t *i)
{
	size_t	tmp;

	++(*i);
	tmp = *i;
	while (*input && (*input)[*i] != '\'')
	{
		if (!(*input)[*i])
			get_line_until_quote(input, '\'');
		++(*i);
	}
	*squote = ft_strndup((*input + tmp), (*i - tmp));
	++(*i);
}

void			expand_double_quotes(char **dquote, char **input, size_t *i)
{
	char	*dollar_sign;
	size_t	tmp;

	++(*i);
	tmp = *i;
	while (*input && (*input)[*i] != '\"')
	{
		if (!(*input)[*i] && (ft_count_c(*input, '\"') % 2))
			get_line_until_quote(input, '\"');
		if ((*input)[*i] == '$')
		{
			*dquote = ft_strndup((*input + tmp), (*i - tmp));
			expand_dollar_sign(&dollar_sign, *input, i);
			*dquote = ft_strcata(dquote, dollar_sign);
		}
		++(*i);
	}
	*dquote = ft_strncata(dquote, (*input + tmp), (*i - tmp));
	++(*i);
}
