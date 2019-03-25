/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:28:07 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/24 21:13:28 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "environment.h"
#include "libft.h"

int		ft_isenv(char *s, int *i)
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

char	*ft_getenv(char	*s)
{
	size_t			env_len;
	int				i;

	i = 0;
	while (g_envs[i])
	{
		env_len = ft_strlend(g_envs[i], '=');
		if (!ft_strncmp(s, g_envs[i], env_len) && s[env_len] == '\0')
			return (ft_strdup(g_envs[i] + env_len + 1));
		++i;
	}
	return (ft_strnew(0));
}

char	**add_env(char *new_env, int num_envs)
{
	char	**new_envs;
	int		i;

	i = 0;
	new_envs = (char **)ft_memalloc(sizeof(char *) * (num_envs + 1));
	while (g_envs && g_envs[i])
	{
		new_envs[i] = ft_strdup(g_envs[i]);
		++i;
	}
	new_envs[i] = ft_strdup(new_env);
	return (new_envs);
}

char	**delete_env(int env_to_delete, int num_envs)
{
	char	**new_envs;
	int		i;

	i = 0;
	new_envs = (char **)ft_memalloc(sizeof(char *) * (num_envs + 1));
	while (num_envs)
	{
		if (i < env_to_delete)
			new_envs[i] = ft_strdup(g_envs[i]);
		else
			new_envs[i] = ft_strdup(g_envs[i + 1]);
		--num_envs;
		++i;
	}
	return (new_envs);
}
