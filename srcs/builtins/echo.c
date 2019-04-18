/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:00:57 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 18:58:28 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "ft_list.h"
#include "ft_printf.h"

int		ft_echo(t_command *command)
{
	t_list	*cur;

	cur = command->args;
	while (cur)
	{
		ft_printf("%s", (cur)->content);
		if ((cur)->next)
			ft_printf(" ");
		cur = (cur)->next;
	}
	ft_printf("\n");
	return (0);
}
