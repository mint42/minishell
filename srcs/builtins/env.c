/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:58:15 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 18:58:28 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "environment.h"
#include "ft_double_array.h"

int		ft_env(t_command *command)
{
	(void)command;
	ft_print_double_array(g_envs);
	return (0);
}
