/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:03:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/22 23:52:13 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "environment.h"
#include "libft.h"

static void		delete_g_env(int i)
{
	char	**new_envs;

	--g_num_envs;
	new_envs = delete_env(i, g_num_envs);
	ft_delete_double_array(&g_envs);
	g_envs = new_envs;
}

int				ft_unsetenv(t_command *command)
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
		if (validate_env(*cur) && (*cur)[env_len] == '\0')
		{
			env = ft_strndup(*cur, env_len);
			ft_isenv(env, &i);
			delete_g_env(i);
			ft_strdel(&env);
		}
		else
			ft_printf("squish: unsetenv: `%s': not a valid identifier\n", *cur);
		++cur;
	}
	return (0);
}
