/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:13:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/18 16:42:53 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_isenv(char *command, int *i)
{
	size_t			env_len;

	*i = 0;
	while (g_envs[*i])
	{
		env_len = ft_strlend(g_envs[*i], '=');
		if (((ft_strncmp(command, g_envs[*i], env_len)) == 0) &&
			command[env_len] == '\0')
			{
				return (1)
			}
		++*i;
	}
	return (0);
}

char	*ft_getenv(char	*command)
{
	size_t			env_len;
	int				i;

	i = 0;
	while (g_envs[i])
	{
		env_len = ft_strlend(g_envs[i], '=');
		if (((ft_strncmp(command, g_envs[i], env_len)) == 0) &&
			command[env_len] == '\0')
			{
				return (ft_strdup(g_envs[i] + env_len + 1));
			}
		++i;
	}
	return (ft_strnew(0));
}

char	*replace_env(char *command, size_t env_len, int i)
{
	char	*new_env;

	new_env = ft_strndup(command, env_len + 1);
	new_env = expand_and_join(command + env_len, new_env);
	return (new_env);
}

char	*add_env(char *command)
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
	new_envs[i] = expand_and_join(command, new_envs[i]);
	new_envs[i + 1] = 0;
	ft_delete_double_array(&g_envs);
	return (new_envs);
}

char	*delete_env(char *command)
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
	return (new_envs);
}
