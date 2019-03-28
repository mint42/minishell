/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:31:03 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/28 01:05:54 by rreedy           ###   ########.fr       */
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
	size_t	place_holder;
	char	c;

	++(*i);
	place_holder = *i;
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
	*dollar_sign = ft_getenv(input + place_holder);
	input[*i] = c;
}

void	expand_regular(char **regular, char *ops, char *input, size_t *i)
{
	size_t	place_holder;

	place_holder = *i;
	while (input && input[*i])
	{
		if (ft_strchr(ops, input[*i]))
			break ;
		++(*i);
	}
	*regular = ft_strndup((input + place_holder), (*i - place_holder));
}
