/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:36:50 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/24 21:30:16 by rreedy           ###   ########.fr       */
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

void			expand_single_quotes(char **squote, char **input)
{
	char	*cur;

	++(*input);
	cur = *input;
	while (cur && *cur != '\'')
	{
		if (!*cur)
			get_line_until_quote(input, '"');
		++cur;
	}
	*squote = ft_strndup(*input, cur - *input);
	*input = ++cur;
}

void			expand_double_quotes(char **dquote, char **input)
{
	char	*cur;
	char	*tmp;

	tmp = 0;
	++(*input);
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
	*dquote = ft_strndup(*input, cur - *input);
	*input = ++cur;
}
