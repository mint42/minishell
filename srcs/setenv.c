/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:02:57 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/18 13:10:56 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_setenv(char	*command)
{
	int			i;

	i = 0;
	command = ft_next_word(command);
	if (ft_isenv(command, &i)
	{
		ft_strdel(&g_envs[i]);
		g_envs[i] = replace_env(command, ft_strlend(g_envs[i], '='), i);
	}
	else if (ft_strchr(command, '='))
		g_envs = add_env(command);
}
