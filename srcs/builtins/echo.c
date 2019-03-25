/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:00:57 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/24 18:18:45 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"

int		ft_echo(t_command *command)
{
	if (command->args)
		ft_printf("%s", *(command->args));
	ft_printf("\n");
	return (0);
}
