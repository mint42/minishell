/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:02:57 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/21 19:30:32 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "environment.h"
#include "libft.h"

static char		*validate_and_isolate_env(char *command)
{
	char	*cur;
	int		error;

	cur = command;
	error = 0;
	if (!cur)
		return (error);
	if (ft_isdigit(*cur))
		error = 1;
	while (cur && *cur)
	{
		if (*cur == '=')
			break ;
		++cur;
	}
	if (*cur == '=')
		*cur = '\0';
}

int				ft_setenv(t_command	*command)
{
	char	**new_envs;
	char	*env;
	int		i;

	i = 0;
	env = 0;
	command = ft_next_word(command);
	while (command && *command)
	{
		if (validate_and_isolate_env(command, &env))
			
		else if (ft_isenv(env, &i))
		{
			ft_strdel(&g_envs[i]);
			g_envs[i] = replace_env(command, ft_strlend(g_envs[i], '='));
		}
		else
		{
			++g_num_envs;
			new_envs = add_env(command, g_num_envs);
			ft_delete_double_array(&g_envs);
			g_envs = new_envs;
		}
		command = ft_next_word(command);
	}
	return (0);
}
