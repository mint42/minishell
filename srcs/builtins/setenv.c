/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:02:57 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/29 13:00:18 by rreedy           ###   ########.fr       */
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
	char	**cur;
	char	*env;
	size_t	env_len;
	int		i;

	i = 0;
	cur = command->args;
	while (cur && *cur)
	{
		env_len = ft_strlend(*cur, '=');
		env = ft_strndup(*cur, env_len);
		if (validate_env(env) && (*cur)[env_len] == '=')
		{
			if (ft_isenv(env, &i))
				replace_env(*cur, i);
			else
				add_env(*cur);
		}
		else
			ft_printf("squish: setenv: `%s': not a valid identifier\n", *cur);
		ft_strdel(&env);
		++cur;
	}
	return (0);
}
