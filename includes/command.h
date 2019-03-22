/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:40:13 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/21 17:41:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

typedef struct	s_command
{
	char		*name;
	char		**args;
	int			argc;
	int			ret;
}				t_command;

t_command		*get_command_struct(char *input)
void			delete_command_struct(t_command **command)

#endif
