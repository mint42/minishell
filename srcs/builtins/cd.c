/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 21:28:09 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/21 19:26:23 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "builtins.h"
#include "environment.h"
#include "libft.h"

static void		update_pwds()
{
	char	*new_pwd;
	char	*old_pwd;
	char	*env;

	new_pwd = getcwd(NULL, 0);
	old_pwd = ft_getenv("PWD");
	env = 0;
	ft_sprintf(&env, "setenv PWD=%s OLDPWD=%s", new_pwd, old_pwd);
	ft_setenv(env);
	ft_strdel(&env);
	ft_strdel(&new_pwd);
	ft_strdel(&old_pwd);
}

int				ft_cd(t_command *command)
{
	char	*new_pwd;

	new_pwd = 0;
	if (command->args)
		new_pwd = *(command->args);
	else
		new_pwd = ft_getenv("HOME");
	if (!(chdir(new_pwd)))
		update_pwds();
	else
		ft_printf("cd: %s: is bad\n", new_pwd);
	ft_strdel(&new_pwd);
	return (0);
}
