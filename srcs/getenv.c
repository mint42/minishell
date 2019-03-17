/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 22:39:27 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/17 01:03:23 by rreedy           ###   ########.fr       */
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
			!ft_isalpha(command[env_len]) &&
			!ft_isdigit(command[env_len]) &&
			command[env_len] != '_')
			{
				return (ft_strdup(g_envs[i] + env_len + 1));
			}
		++i;
	}
	return (ft_strnew(0));
}
