/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:31:03 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 19:00:18 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "expansions.h"
#include "ft_str.h"
#include "ft_utils.h"

void	expand_tilde(char **s, char *input, size_t *i)
{
	const char	*tilde;

	++(*i);
	(void)input;
	tilde = ft_getenv("HOME");
	*s = ft_strcata(s, tilde);
}

void	expand_dollar_sign(char **s, char *input, size_t *i)
{
	const char	*dollar_sign;
	size_t		place_holder;
	char		c;

	++(*i);
	place_holder = *i;
	dollar_sign = 0;
	if (input[*i] && ft_isdigit(input[*i]))
		return ;
	while (input && input[*i])
	{
		if (!ft_isalnum(input[*i]) && input[*i] != '_')
			break ;
		++(*i);
	}
	c = input[*i];
	input[*i] = '\0';
	dollar_sign = ft_getenv(input + place_holder);
	input[*i] = c;
	*s = ft_strcata(s, dollar_sign);
}

void	expand_backslash(char **s, char *input, size_t *i, int quotes)
{
	char	*backslash;

	if (!quotes || (input[*i + 1] && ft_strchr("$\"\\", input[*i + 1])))
		++(*i);
	backslash = input + *i;
	*s = ft_strncata(s, backslash, 1);
	++(*i);
}

void	expand_quotes(char **quote, char c, char *input, size_t *i)
{
	++(*i);
	if (c == '\'')
		expand_regular(quote, "\'", input, i);
	else
	{
		while (input && input[*i] && input[*i] != '\"')
		{
			if (input[*i] == '$')
				expand_dollar_sign(quote, input, i);
			else if (input[*i] == '\\')
				expand_backslash(quote, input, i, 1);
			else
				expand_regular(quote, "$\\\"", input, i);
		}
	}
	++(*i);
}

void	expand_regular(char **s, const char *op, char *input, size_t *i)
{
	char	*regular;
	size_t	place_holder;

	place_holder = *i;
	while (input && input[*i])
	{
		if (ft_strchr(op, input[*i]))
			break ;
		++(*i);
	}
	regular = input + place_holder;
	*s = ft_strncata(s, regular, *i - place_holder);
}
