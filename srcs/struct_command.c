/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:29:18 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/01 14:19:01 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"

t_command	*init_command_struct(void)
{
	t_command	*command;

	command = (t_command *)ft_memalloc(sizeof(t_command));
	command->name = 0;
	command->args = 0;
	command->argc = 0;
	command->index = 0;
	command->ret = 0;
	return (command);
}

void		delete_command_struct(t_command **command)
{
	if (*command)
	{
		if ((*command)->name)
			ft_strdel(&((*command)->name));
		if ((*command)->args)
			ft_lstdel(&((*command)->args), ft_lstdelcontent);
		ft_memdel((void **)command);
	}
}
