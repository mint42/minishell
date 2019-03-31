/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:40:13 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/31 13:03:54 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

typedef struct s_list	t_list;

typedef struct	s_command
{
	char		*name;
	t_list		*args;
	int			argc;
	int			index;
	int			ret;
}				t_command;

t_command		*init_command_struct(void);
void			delete_command_struct(t_command **comm);

#endif
