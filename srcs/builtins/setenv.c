/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:02:57 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/31 13:15:24 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "environment.h"
#include "libft.h"


static int		validate_env(char *env)
{
	char	*cur;
	int		error;

	cur = env;
	error = 0;
	if (!cur || !*cur)
		error = 1;
	if (ft_isdigit(*cur))
		error = 1;
	while (!error && cur && *cur)
	{
		if (!ft_isdigit(*cur) && !ft_isalpha(*cur) && *cur != '_')
			error = 1;
		++cur;
	}
	return (!error);
}

int				ft_setenv(t_command	*command)
{
	char	*arg;
	char	*env;
	size_t	env_len;
	int		i;

	i = 0;
	while (command->args)
	{
		arg = (command->args)->content;
		env_len = ft_strlend(arg, '=');
		env = ft_strndup(arg, env_len);
		if (validate_env(env) && (arg)[env_len] == '=')
		{
			if (ft_isenv(env, &i))
				replace_env(arg, i);
			else
				add_env(arg);
		}
		else
			ft_printf("squish: setenv: `%s': not a valid identifier\n", arg);
		ft_strdel(&env);
		command->args = (command->args)->next;
	}
	return (0);
}
