/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:58:15 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/21 19:25:40 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "environment.h"
#include "libft.h"

int		ft_env(t_command *command)
{
	//need to be able to do this on different folders, or something
	(void)command;
	ft_print_double_array(g_envs);
	return (0);
}
