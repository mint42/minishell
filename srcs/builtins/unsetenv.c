/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:03:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/21 19:30:21 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "environment.h"
#include "libft.h"

void			ft_unsetenv(t_command *command)
{
	char	**new_envs;
	int		i;

	i = 0;
	command = ft_next_word(command);
	while (command && *command)
	{
		if (ft_isenv(command, &i))
		{
			--g_num_envs;
			new_envs = delete_env(i, g_num_envs);
			ft_delete_double_array(&g_envs);
			g_envs = new_envs;
		}
		command = ft_next_word(command);
	}
	return (0);
}
