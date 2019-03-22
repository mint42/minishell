/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:31:03 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/21 20:50:09 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "environment.h"

char	*expand_single_quote(char **s)
{
	char	*quote;
}

char	*expand_double_quote(char **s)
{
	char	*quote;
}

char	*expand_tilde(char **s)
{
	char	*tilde;
	++(*s);
	*tilde = ft_getenv("HOME");
	return (tilde);
}

char	*expand_dollar_sign(char **s)
{
	char	*dollar_sign;
	char	*cur;

	++(*command);
	cur = *command;
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
	*dollar_sign = ft_getenv(*command);
	*command = cur;
	return (dollar_sign);
}

char	*expand_regular(char **s)
{

}
