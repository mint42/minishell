/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:02:57 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/22 23:49:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "environment.h"
#include "libft.h"

static void		replace_g_env(char *new_env, int i)
{
	ft_strdel(&g_envs[i]);
	g_envs[i] = ft_strdup(new_env);
}

static void		add_g_env(char *new_env)
{
	char	**new_envs;

	++g_num_envs;
	new_envs = add_env(new_env, g_num_envs);
	ft_delete_double_array(&g_envs);
	g_envs = new_envs;
}

int				ft_setenv(t_command	*command)
{
	char	**cur;
	char	*env;
	size_t	env_len;
	int		i;

	i = 0;
	cur = command->args;
	while (cur && *cur)
	{
		env_len = ft_strlend(*cur, '=');
		if (validate_env(*cur) && (*cur)[env_len] == '=')
		{
			env = ft_strndup(*cur, env_len);
			if (ft_isenv(env, &i))
				replace_g_env(*cur, i);
			else
				add_g_env(*cur);
			ft_strdel(&env);
		}
		else
			ft_printf("squish: setenv: `%s': not a valid identifier\n", *cur);
		++cur;
	}
	return (0);
}
