/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:56:44 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/29 18:46:32 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define TOTAL_BUILTINS (7)
# define ECHO_INDEX (1)

typedef struct s_command	t_command;

static char		*g_builtins[TOTAL_BUILTINS + 1] =
{
	"cd",
	"echo",
	"env",
	"exit",
	"pwd",
	"setenv",
	"unsetenv",
	0,
};

int				ft_cd(t_command *command);
int				ft_echo(t_command *command);
int				ft_env(t_command *command);
int				ft_exit(t_command *command);
int				ft_pwd(t_command *command);
int				ft_setenv(t_command *command);
int				ft_unsetenv(t_command *command);

#endif
