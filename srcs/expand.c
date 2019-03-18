/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 22:37:00 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/18 16:42:51 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_tilde(char **command, char **tilde)
{
	++(*command);
	(void)tilde;
	*newe = ft_getenv("HOME");
}

void	expand_dollar_sign(char **command, char **dollar_sign)
{
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
}

char	*expand_and_join(char *command, char *s)
{
	char	*cur;
	char	*tmp;

	tmp = 0;
	if (*command == '~')
	{
		expand_tilde(&command, &tmp);
		s = ft_strcata(&s, tmp);
		ft_strdel(&tmp);
		++command;
	}
	cur = command;
	while (cur && *cur && !ft_isspace(*cur))
	{
		while (*cur && !ft_strchr(" \t\n\v\f\r$\'\"", *cur))
			++cur;
		s = ft_strncata(&s, command, cur - command);
		if (*cur == '$')
		{
			expand_dollar_sign(&cur, &tmp);
			s = ft_strcata(&s, tmp);
			ft_strdel(&tmp);
		}
		command = cur;
	}
	return (s);
}
