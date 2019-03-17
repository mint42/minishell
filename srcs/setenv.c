/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:02:57 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/17 03:56:10 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		replace_env(char *command, int env_len, int i)
{
	char	*new_env;
	char	*tilde;

	ft_strdel(&g_envs[i]);
	new_env = ft_strndup(command, env_len);
	command = command + env_len;
	if (*command == '~')
	{
		expand_tilde(&command, &tilde);
		new_env = ft_strcata(&new_env, tilde);
		ft_strdel(&tilde);
		++command;
	}
	new_env = expand_and_join(command, new_env);
	g_envs[i] = new_env;
}

static void		add_env(char *command)
{
	char	**new_envs;
	int		i;

	i = 0;
	while (g_envs && g_envs[i])
		++i;
	new_envs = (char **)ft_memalloc(sizeof(char *) * (i + 2));
	i = 0;
	while (g_envs && g_envs[i])
	{
		new_envs[i] = ft_strdup(g_envs[i]);
		++i;
	}
	new_envs[i] = ft_strdup(command);
	new_envs[i + 1] = 0;
	ft_delete_double_array(&g_envs);
	g_envs = new_envs;
}

void			ft_setenv(char	*command)
{
	size_t		env_len;
	int			i;

	i = 0;
	env_len = 0;
	command = ft_next_word(command);
	while (g_envs[i])
	{
		env_len = ft_strlend(g_envs[i], '=');
		if (((ft_strncmp(command, g_envs[i], env_len)) == 0) && 
			command[env_len] == '=')
		{
			replace_env(command, env_len, i);
			return ;
		}
		++i;
	}
	if (ft_strchr(command, '='))
		add_env(command);
}
