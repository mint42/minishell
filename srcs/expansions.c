/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:31:03 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/24 21:22:55 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "expand.h"
#include "libft.h"

void	expand_tilde(char **tilde, char **input)
{
	++(*input);
	*tilde = ft_getenv("HOME");
}

void	expand_dollar_sign(char **dollar_sign, char **input)
{
	char	*cur;
	char	tmp;

	++(*input);
	cur = *input;
	if (cur && ft_isdigit(*cur))
	{
		*dollar_sign = ft_strnew(0);
		return ;
	}
	while (cur && *cur)
	{
		if (!ft_isalnum(*cur) && *cur != '_')
			break ;
		++cur;
	}
	tmp = *cur;
	*cur = '\0';
	*dollar_sign = ft_getenv(*input);
	*cur = tmp;
	*input = cur;
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

void	expand_regular_with_space(char **space, char **input)
{
	char	*cur;

	cur = *input;
	while (cur && *cur)
	{
		if (ft_strchr("$\'\"", *cur))
			break ;
		++cur;
	}
	*space = ft_strndup(*input, cur - *input);
	*input = cur;
}
