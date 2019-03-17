/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 21:28:09 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/17 03:14:01 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		update_pwds(char **new_pwd)
{
	char	*old_pwd;
	char	*env;

	ft_strdel(new_pwd);
	*new_pwd = getcwd(NULL, 0);
	old_pwd = ft_getenv("PWD");
	env = 0;
	ft_sprintf(&env, "setenv OLDPWD=%s", old_pwd);
	ft_setenv(env);
	ft_strdel(&env);
	ft_sprintf(&env, "setenv PWD=%s", *new_pwd);
	ft_setenv(env);
	ft_strdel(&env);
	ft_strdel(&old_pwd);
}

void			ft_cd(char *command)
{
	char	*new_pwd;

	new_pwd = 0;
	command = ft_next_word(command);
	if (command && *command == '~')
		expand_tilde(&command, &new_pwd);
	else if (command && *command == '\0')
		new_pwd = ft_getenv("HOME");
	if (command && *command && !ft_isspace(*command))
		new_pwd = expand_and_join(command, new_pwd);
	if (!(chdir(new_pwd)))
		update_pwds(&new_pwd);
	else
		ft_printf("cd: %s: is bad\n", new_pwd);
	ft_strdel(&new_pwd);
}
