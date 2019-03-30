/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:40:13 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/29 18:42:48 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# define RET(command) (((t_command *)((command)->content))->ret)
# define INDEX(command) (((t_command *)((command)->content))->index)

typedef struct	s_command
{
	char		*name;
	char		**args;
	int			argc;
	int			index;
	int			ret;
}				t_command;

t_command		*init_command_struct(void);
void			delete_command_struct(t_command **comm);

#endif
