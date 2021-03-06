/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:28:07 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 18:55:35 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_mem.h"
#include "ft_str.h"

int			ft_isenv(const char *s, int *i)
{
	size_t			env_len;

	*i = 0;
	while (g_envs[*i])
	{
		env_len = ft_strlend(g_envs[*i], '=');
		if (!ft_strncmp(s, g_envs[*i], env_len) && s[env_len] == '\0')
			return (1);
		++(*i);
	}
	return (0);
}

const char	*ft_getenv(const char *s)
{
	size_t			env_len;
	int				i;

	i = 0;
	while (g_envs[i])
	{
		env_len = ft_strlend(g_envs[i], '=');
		if (!ft_strncmp(s, g_envs[i], env_len) && s[env_len] == '\0')
			return (g_envs[i] + env_len + 1);
		++i;
	}
	return (0);
}

void		replace_env(const char *new_env, int i)
{
	ft_strdel(&g_envs[i]);
	g_envs[i] = ft_strdup(new_env);
}

void		add_env(const char *new_env)
{
	char	**new_envs;
	int		i;

	i = 0;
	++g_num_envs;
	new_envs = (char **)ft_memalloc(sizeof(char *) * (g_num_envs + 1));
	while (g_envs && g_envs[i])
	{
		new_envs[i] = g_envs[i];
		++i;
	}
	new_envs[i] = ft_strdup(new_env);
	ft_memdel((void **)&g_envs);
	g_envs = new_envs;
}

void		delete_env(int env_to_delete)
{
	char	**new_envs;
	int		i;

	i = 0;
	--g_num_envs;
	new_envs = (char **)ft_memalloc(sizeof(char *) * (g_num_envs + 1));
	while (i < g_num_envs)
	{
		if (i < env_to_delete)
			new_envs[i] = g_envs[i];
		else
			new_envs[i] = g_envs[i + 1];
		++i;
	}
	ft_strdel(&g_envs[env_to_delete]);
	ft_memdel((void **)&g_envs);
	g_envs = new_envs;
}
