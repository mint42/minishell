/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:03:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/24 16:18:29 by rreedy           ###   ########.fr       */
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
	int		i;

	i = 0;
	cur = command->args;
	while (cur && *cur)
	{
		if (ft_isenv(*cur, &i))
			delete_g_env(i);
		else
		{
			ft_printf("squish: unsetenv: `%s': not a valid identifier\n", *cur);
			return (1);
		}
		++cur;
	}
	return (0);
}
