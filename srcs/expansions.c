/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:31:03 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/22 22:55:11 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "environment.h"

void	expand_tilde(char **tilde, char **input)
{
	++(*input);
	*tilde = ft_getenv("HOME");
}

void	expand_dollar_sign(char **dollar_sign, char **input)
{
	char	*cur;

	++(*input);
	cur = *input;
	if (cur && ft_isdigit(*cur))
	{
		*dollar_sign = ft_strnew(0);
		return ;
	}
	while (cur && *cur)
	{
		if (!ft_isalpha(*cur) && !ft_isdigit(*cur) && *cur != '_')
			break ;
		++cur;
	}
	*cur = '\0';
	*dollar_sign = ft_getenv(*input);
	*input = cur;
}

void	get_line_until_quote(char **input, char c)
{
	char	*line;
	size_t	len;

	line = 0;
	while (42)
	{
		ft_printf(">");
		if ((get_next_line(1, &line)) != 1)
			continue;
		len = (line) ? ft_strlen(line) : 1;
		line[len - 1] = '\n';
		*input = ft_strncata(input, line, len);
		if (ft_strchr(line, c))
		{
			*input = ft_strncata(input, "\0", 1);
			break ;
		}
	}
}

void	expand_single_quotes(char **squote, char **input)
{
	char	*cur;

	cur = *input;
	while (cur && *cur != '\'')
	{
		if (!*cur)
			get_line_until_quote(input, '"');
		++cur;
	}
	*squote = ft_strndup(*input, cur - *input - 1);
	*input = ++cur;
}

void	expand_double_quotes(char **dquote, char **input)
{
	char	*cur;
	char	*tmp;

	tmp = 0;
	cur = *input;
	while (cur && *cur != '\"')
	{
		if (!*cur)
			get_line_until_quote(input, '"');
		if (*cur == '$')
		{
			*dquote = ft_strndup(*input, cur - *input);
			expand_dollar_sign(&tmp, &cur);
			*dquote = ft_strcata(dquote, tmp);
			*input = cur;
		}
		++cur;
	}
	*dquote = ft_strndup(*input, cur - *input - 1);
	*input = ++cur;
}

void	expand_regular(char **regular, char **input)
{
	char	*cur;

	cur = *input;
	while (cur && *cur)
	{
		if (ft_strchr(" \t\n\v\f\r$\'\"", *cur))
			break ;
		++cur;
	}
	*regular = ft_strndup(*input, cur - *input);
	*input = cur;
}
