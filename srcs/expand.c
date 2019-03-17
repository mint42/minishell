/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 22:37:00 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/17 01:54:13 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_tilde(char **command, char **newe)
{
	++(*command);
	*newe = ft_getenv("HOME");
}

void	expand_dollar_sign(char **command, char **env)
{
	char	*cur;

	++(*command);
	cur = *command;
	if (cur && ft_isdigit(*cur))
	{
		*env = ft_strnew(0);
		return ;
	}
	while (cur && *cur)
	{
		if (!ft_isalpha(*cur) && !ft_isdigit(*cur) && *cur != '_')
			break ;
		++cur;
	}
	*cur = '\0';
	*env = ft_getenv(*command);
	*command = cur;
}

char	*expand_and_join(char *command, char *newe)
{
	char	*cur;
	char	*env;

	cur = command;
	env = 0;
	while (cur && *cur && !ft_isspace(*cur))
	{
		while (cur && *cur && !ft_strchr(" \t\n\v\f\r$", *cur))
			++cur;
		if (cur && *cur != '$')
			newe = ft_strncata(&newe, command, cur - command);
		else
		{
			expand_dollar_sign(&cur, &env);
			newe = ft_strcata(&newe, env);
			ft_strdel(&env);
		}
	}
	return (newe);
}
