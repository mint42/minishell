/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:02:57 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/03 13:23:36 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "environment.h"
#include "libft.h"

static void		print_error(char *s)
{
	ft_printf("squish: setenv: `%s': not a valid identifier\n", s);
}

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

int				ft_setenv(t_command *command)
{
	char	*env;
	size_t	env_len;
	int		i;
	t_list	*cur;

	i = 0;
	env = 0;
	cur = command->args;
	while (cur)
	{
		env_len = ft_strlend((cur)->content, '=');
		env = ft_strndup((cur)->content, env_len);
		if (validate_env(env) && ((char *)((cur)->content))[env_len] == '=')
		{
			if (ft_isenv(env, &i))
				replace_env((cur)->content, i);
			else
				add_env((cur)->content);
		}
		else
			print_error((cur)->content);
		ft_strdel(&env);
		cur = (cur)->next;
	}
	return (0);
}
