/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:10:06 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/28 01:24:29 by rreedy           ###   ########.fr       */
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
		len = ft_strlen(line);
		if (ft_strchr(line, c))
		{
			*input = ft_strncata(input, line, len);
			break ;
		}
		else
		{
			line = ft_strcata(&line, "\n\0");
			*input = ft_strncata(input, line, len + 1);
		}
		ft_strdel(&line);
	}
}

void			expand_single_quotes(char **squote, char **input, size_t *i)
{
	size_t	place_holder;

	++(*i);
	while (*input && ((*input)[*i] || (ft_count_c(*input, '\'') % 2)))
	{
		if (!(*input)[*i])
			get_line_until_quote(input, '\'');
		place_holder = *i;
		while (input && (*input)[*i] && (*input)[*i] != '\'')
			++(*i);
		*squote = ft_strncata(squote, *input + place_holder, *i - place_holder);
		if ((*input)[*i] == '\'')
			++(*i);
	}
}

void			expand_double_quotes(char **dquote, char **input, size_t *i)
{
	char	*tmp;

	++(*i);
	tmp = 0;
	while (*input && ((*input)[*i] || (ft_count_c(*input, '\"') % 2)))
	{
		if (!(*input)[*i])
			get_line_until_quote(input, '\"');
		if ((*input)[*i] == '$')
			expand_dollar_sign(&tmp, *input, i);
		else
			expand_regular(&tmp, "$\"", *input, i);
		*dquote = ft_strcata(dquote, tmp);
		ft_strdel(&tmp);
		if ((*input)[*i] == '\"')
			++(*i);
	}
}
