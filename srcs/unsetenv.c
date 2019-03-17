/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:03:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/17 04:10:27 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		delete_env(char *command)
{
	char	**new_envs;
	size_t	env_len;
	int		i;

	i = 0;
	while (g_envs && g_envs[i])
		++i;
	new_envs = (char **)ft_memalloc(sizeof(char *) * i);
	i = 0;
	env_len = 0;
	while (g_envs && g_envs[i])
	{
		env_len = ft_strlend(g_envs[i], '=');
		if (((ft_strncmp(command, g_envs[i], env_len)) == 0) && 
			command[env_len] == '\0')
		{
			continue;
		}
		new_envs[i] = ft_strdup(g_envs[i]);
		++i;
	}
	new_envs[i] = 0;
	ft_delete_double_array(&g_envs);
	g_envs = new_envs;
}

void		ft_unsetenv(char *command)
{
	char	*env;
	char	*cur;

	command = ft_next_word(command);
	cur = ft_skiptospace(command);
	*cur = '\0';
	env = ft_getenv(command);
	if (env)
		delete_env(command);
	ft_strdel(&env);
}
