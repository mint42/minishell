/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:02:57 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/17 01:25:27 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		replace_env(char *command, int env_len, int i)
{
	char	*tilde;
	char	*new_env;
	char	*cur;

	ft_strdel(&g_envs[i]);
	cur = command + env_len;
	new_env = ft_strndup(command, env_len);
	if (*cur == '~')
	{
		tilde = expand_tilde(cur);
		new_env = ft_strcata(&new_env, tilde);
		ft_strdel(&tilde);
		++cur;
	}
	new_env = expand_and_join(cur, new_env);
	g_envs[i] = new_env;
}

static void		add_env(char *command)
{
	char	**new_envs;
	char	**cur;
	int		i;

	i = 0;
	cur = g_envs;
	while (cur && cur[i])
		++i;
	new_envs = (char **)ft_memalloc(sizeof(char *) * (i + 2));
	i = 0;
	while (g_envs && *g_envs)
	{
		new_envs[i] = ft_strdup(*g_envs);
		++g_envs;
		++i;
	}
	new_envs[i] = ft_strdup(command);
	ft_delete_double_array(&g_envs);
	g_envs = new_envs;
}

void			ft_setenv(char	*command)
{
	char		*new_path;
	size_t		env_len;
	int			i;

	i = 0;
	new_path = 0;
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
