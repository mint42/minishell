/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:02:03 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 18:58:28 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "environment.h"
#include "ft_printf.h"

int		ft_pwd(t_command *command)
{
	(void)command;
	ft_printf("%s\n", ft_getenv("PWD"));
	return (0);
}
