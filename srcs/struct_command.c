/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:29:18 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/21 19:16:27 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "expand.h"
#include "libft.h"

t_command	*get_command_struct(char *input)
{
	struct t_command	*command;

	command = (t_command *)ft_memalloc(sizeof(t_command));
	command->name = 0;
	command->args = 0;
	command->argc = 0;
	command->ret = 0;
	if (input)
	{
		expand_string(&(command->name), &input, 0);
		expand_args(&(command->args), &(command->argc), input);
	}
	return (command);
}

void		delete_command_struct(t_command **command)
{
	if (*command)
	{
		if ((*command)->command)
			ft_strdel(&((*command)->command));
		if ((*command)->args)
			ft_delete_double_array(&((*command)->args));
		ft_memdel((void **)command);
	}
}