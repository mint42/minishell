/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:02:57 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/22 18:21:47 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "environment.h"
#include "libft.h"

static char		*isolate_env(char *env, size_t len)
{
	if (len)
		env[len - 1] = '\0';
	return (ft_strdup(env));
}

static int		validate_env(char *command)
{
	char	*cur;
	int		error;

	cur = command;
	error = 0;
	if (!cur)
		return (error);
	if (ft_isdigit(*cur))
		error = 1;
	while (!error && cur && *cur && *cur != '=')
	{
		if (!ft_isdigit(*cur) && !ft_isalpha(*cur) && *cur != '_')
			error = 1;
		++cur;
	}
	if (error)
		ft_printf("squish: setenv: `%s': not a valid identifier\n", command);
	return (!error);
}

static void		replace_g_env(cur, len)
{
	ft_strdel(&g_envs[i]);
	g_envs[i] = replace_env(cur, len);
}

static void		add_g_env(cur)
{
	char	**new_envs;

	++g_num_envs;
	new_envs = add_env(cur, g_num_envs);
	ft_delete_double_array(&g_envs);
	g_envs = new_envs;
}

int				ft_setenv(t_command	*command)
{
	char	**cur;
	char	*env;
	size_t	len;

	cur = command->args;
	while (cur)
	{
		if (validate_env(cur))
		{
			len = ft_strlend(cur, '=');
			env = isolate_env(cur, len);
			if (ft_isenv(env, &i))
				replace_g_env(cur, len);
			else
				add_g_env(cur);
			ft_strdel(&env);
		}
		++cur;
	}
	return (0);
}
