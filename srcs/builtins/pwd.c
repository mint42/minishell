/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:02:03 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/22 16:59:18 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "environment.h"
#include "libft.h"

int		ft_pwd(t_command *command)
{
	char	*pwd;

	(void)command;
	pwd = ft_getenv("PWD");
	ft_printf("%s\n", pwd);
	ft_strdel(&pwd);
	return (0);
}
