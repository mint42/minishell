/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 21:28:09 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/24 21:40:43 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "command.h"
#include "environment.h"
#include "expand.h"
#include "libft.h"
#include <unistd.h>

static void		update_pwds()
{
	t_command	*command;
	char		*new_pwd;
	char		*old_pwd;
	char		*format;

	new_pwd = getcwd(NULL, 0);
	old_pwd = ft_getenv("PWD");
	ft_sprintf(&format, "PWD=%s OLDPWD=%s", new_pwd, old_pwd);
	command = init_command_struct();
	expand_args(&(command->args), &(command->argc), format);
	ft_setenv(command);
	ft_strdel(&format);
	ft_strdel(&new_pwd);
	ft_strdel(&old_pwd);
	delete_command_struct(&command);
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
		ft_printf("squish: cd: %s: is bad\n", new_pwd);
	return (0);
}
