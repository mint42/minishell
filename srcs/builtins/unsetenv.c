/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:03:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/22 18:31:38 by rreedy           ###   ########.fr       */
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
	size_t	len;

	cur = command->args;
	while (cur)
	{
		if (validate_env(cur))
		{
			len = ft_strlend(cur, '=');
			env = isolate_env(cur, len);
			if (ft_isenv(env, &i))
				delete_g_env(i);
			ft_strdel(&env);
		}
		++cur;
	}
	return (0);
}
