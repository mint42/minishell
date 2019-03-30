/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:31:03 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/29 16:50:24 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "expansions.h"
#include "libft.h"

void	expand_tilde(char **s, char *input, size_t *i)
{
	char	*tilde;

	++(*i);
	(void)input;
	tilde = ft_getenv("HOME");
	*s = ft_strcata(s, tilde);
	ft_strdel(&tilde);
}

void	expand_dollar_sign(char **s, char *input, size_t *i)
{
	char	*dollar_sign;
	size_t	place_holder;
	char	c;

	++(*i);
	place_holder = *i;
	if (input[*i] && ft_isdigit(input[*i]))
	{
		dollar_sign = ft_strnew(0);
		return ;
	}
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
	ft_strdel(&dollar_sign);
}

void	expand_regular(char **s, char *op, char *input, size_t *i)
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
	regular = ft_strndup((input + place_holder), (*i - place_holder));
	*s = ft_strcata(s, regular);
	ft_strdel(&regular);
}
