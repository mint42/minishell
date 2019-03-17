/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:58:15 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/17 00:45:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

void		ft_env(char *command)
{
	//need to be able to do this on different folders, or something
	(void)command;
	ft_print_double_array(g_envs);
}
