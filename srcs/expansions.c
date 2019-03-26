/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:31:03 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/25 17:37:12 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "expand.h"
#include "libft.h"

void	expand_tilde(char **tilde, char *input, size_t *i)
{
	(void)input;
	++(*i);
	*tilde = ft_getenv("HOME");
}

void	expand_dollar_sign(char **dollar_sign, char *input, size_t *i)
{
	size_t	tmp;
	char	c;

	++(*i);
	tmp = *i;
	if (input[*i] && ft_isdigit(input[*i]))
	{
		*dollar_sign = ft_strnew(0);
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
	*dollar_sign = ft_getenv(input + tmp);
	input[*i] = c;
}

void	expand_regular(char **regular, char *input, size_t *i)
{
	size_t	tmp;

	tmp = *i;
	while (input && input[*i])
	{
		if (ft_strchr(" \t\n\v\f\r$\'\";", input[*i]))
			break ;
		++(*i);
	}
	*regular = ft_strndup((input + tmp), (*i - tmp));
}

void	expand_regular_with_space(char **space, char *input, size_t *i)
{
	size_t	tmp;

	tmp = *i;
	while (input && input[*i])
	{
		if (ft_strchr("$\'\";", input[*i]))
			break ;
		++(*i);
	}
	*space = ft_strndup((input + tmp), (*i - tmp));
}
