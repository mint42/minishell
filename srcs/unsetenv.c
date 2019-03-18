/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:03:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/18 16:44:33 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_unsetenv(char *command)
{
	char	*cur;
	int		i;

	i = 0;
	command = ft_next_word(command);
	cur = ft_skiptospace(command);
	*cur = '\0';
	if (ft_isenv(command, &i))
		g_envs = delete_env(command);
}
