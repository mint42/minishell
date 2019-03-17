/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 22:39:27 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/17 03:42:13 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char	*command)
{
	size_t			env_len;
	int				i;

	i = 0;
	while (g_envs[i])
	{
		env_len = ft_strlend(g_envs[i], '=');
		if (((ft_strncmp(command, g_envs[i], env_len)) == 0) &&
			command[env_len] == '\0')
			{
				return (ft_strdup(g_envs[i] + env_len + 1));
			}
		++i;
	}
	return (ft_strnew(0));
}
